#include <stdio.h>
#include <vector>
#include <queue>
#define pii pair<int,int>
#define ff first
#define ss second
#define mp make_pair
using namespace std;

const int N = 6e2;
int pr[N*N], sz[N*N];

void make_set(int v) {
    pr[v] = v;
    sz[v] = 1;
}

int find_set(int v) {
    if(pr[v] == v) return v;
    return pr[v] = find_set(pr[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if(a != b) {
        if(sz[a] < sz[b]) swap(a, b);
        pr[b] = a;
        sz[a] += sz[b];
    }
}

char a[N][N], viz[N][N];
int b[N][N], go[][2] = {0,1, 0,-1, 1,0, -1,0};
vector<int> e(N*N, -1);

int main()
{
    int n, k, cnt = 0;
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++) {
        char ch; scanf("%c", &ch);
        for(int j = 0; j < n; j++) {
            scanf("%c", &a[i][j]);
            if(a[i][j] == '.') {
                make_set(cnt);
                b[i][j] = cnt++;
            }
            viz[i][j] = false;
        }
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(a[i][j] == '.' && viz[i][j] == false) {
                queue<pii> q;
                q.push(mp(i, j));
                viz[i][j] = true;
                while(!q.empty()) {
                    pii c = q.front();
                    q.pop();
                    for(int w = 0; w < 4; w++) {
                        int ii = c.ff + go[w][0],
                            jj = c.ss + go[w][1];
                        if(ii >= 0 && ii < n && jj >= 0 && jj < n && a[ii][jj] == '.' && viz[ii][jj] == false) {
                            viz[ii][jj] = true;
                            q.push(mp(ii, jj));
                            union_sets(b[c.ff][c.ss], b[ii][jj]);
                        }
                    }
                }
            }
    int res = 0, timer = 0;
    for(int i = k - 1; i < n; i++) {
        vector<int> cu(cnt, 0);
        for(int p = i - k + 1; p <= i; p++)
            for(int q = 0; q < k; q++)
                if(a[p][q] == '.')
                    cu[find_set(b[p][q])]++;
        for(int j = k - 1; j < n; j++) {
            if(j >= k)
                for(int p = i - k + 1; p <= i; p++) {
                    if(a[p][j - k] == '.')
                        cu[find_set(b[p][j - k])]--;
                    if(a[p][j] == '.')
                        cu[find_set(b[p][j])]++;
                }
            int cur = k * k;
            vector<int> add;
            for(int p = i - k + 1; p <= i; p++) {
                if(j - k >= 0 && a[p][j - k] == '.')
                    add.push_back(find_set(b[p][j - k]));
                if(j < n - 1 && a[p][j + 1] == '.')
                    add.push_back(find_set(b[p][j+1]));
            }
            for(int q = j - k + 1; q <= j; q++) {
                if(i >= 0 && a[i - k][q] == '.')
                    add.push_back(find_set(b[i - k][q]));
                if(i < n - 1 && a[i + 1][q] == '.')
                    add.push_back(find_set(b[i + 1][q]));
            }
            for(int u = 0, siz = add.size(); u < siz; u++)
                if(e[add[u]] != timer) {
                    e[add[u]] = timer;
                    cur += sz[add[u]] - cu[add[u]];
                }
            res = max(res, cur);
            timer++;
        }
    }
    printf("%d", res);
    return 0;
}