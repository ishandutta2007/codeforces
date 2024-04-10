#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 2005;
const int INF = 0x3f3f3f3f;

int N, S;
int a[MAXN];
vector <int> E[MAXN];
int dp[2][MAXN];
int trans[MAXN][MAXN];
int lo[MAXN][MAXN], hi[MAXN][MAXN];
bool dir[MAXN][MAXN];
int dad[MAXN];
bool bio[MAXN];

void load() {
    scanf("%d%d", &N, &S);
    for (int i = 0; i < N; i++)
        scanf("%d", a + i);
}

int cw(int x, int y) {
    return x == y ? N : (y - x + N) % N;
}

int ccw(int x, int y) {
    return x == y ? N : (x - y + N) % N;
}

void compute(int x, int c) {
    if (E[c].empty()) return;
    int pos = lower_bound(E[c].begin(), E[c].end(), x + 1) - E[c].begin();
    if (pos >= E[c].size()) pos = 0;
    int sz = E[c].size(), last = x, maks = 0;
    int left, right;
    for (int i = pos; ; i = (i + 1) % sz) {
        int curr = E[c][i];
        int len = cw(last, curr);
        if (len > maks) {
            maks = len;
            left = last;
            right = curr;
        }
        dir[x][curr] = true;
        lo[x][curr] = left;
        hi[x][curr] = right;
        trans[x][curr] = cw(x, curr) - 2 * maks + N;
        last = curr;
        if (i == (pos + sz - 1) % sz) break;
    }
    
    pos = lower_bound(E[c].begin(), E[c].end(), x) - E[c].begin() - 1;
    if (pos < 0) pos = sz - 1;
    last = x, maks = 0;
    for (int i = pos; ; i = (i + sz - 1) % sz) {
        int curr = E[c][i];
        int len = ccw(last, curr);
        if (len > maks) {
            maks = len;
            left = last;
            right = curr;
        }
        int tmp = ccw(x, curr) - 2 * maks + N;
        if (tmp < trans[x][curr]) {
            dir[x][curr] = false;
            lo[x][curr] = left;
            hi[x][curr] = right;
            trans[x][curr] = tmp;
        }
        last = curr;
        if (i == (pos + 1) % sz) break;
    }
}

void go_cw(int start, int fin, int c, int spec) {
    int cnt = 0;
    for (int i = start; ; i = (i + 1) % N) {
        if (a[i] == c && i != spec && !bio[i]) {
            printf("+%d\n", cnt);
            bio[i] = true;
            cnt = 0;
        }
        cnt++;
        if (i == fin) break;
    }
}

void go_ccw(int start, int fin, int c, int spec) {
    int cnt = 0;
    for (int i = start; ; i = (i + N - 1) % N) {
        if (a[i] == c && i != spec && !bio[i]) {
            printf("-%d\n", cnt);
            bio[i] = true;
            cnt = 0;
        }
        cnt++;
        if (i == fin) break;
    }
}

void reconstruct(int x, int y) {
    int c = a[y];
    if (dir[x][y]) {
        go_cw(x, lo[x][y], c, -1);
        go_ccw(lo[x][y], hi[x][y], c, hi[x][y] == y ? -1 : y);
        go_cw(hi[x][y], y, c, -1);
    }
    else {
        go_ccw(x, lo[x][y], c, -1);
        go_cw(lo[x][y], hi[x][y], c, hi[x][y] == y ? -1 : y);
        go_ccw(hi[x][y], y, c, -1);
    }
}

void solve() {
    S--;
    vector <int> V(a, a + N);
    sort(V.begin(), V.end());
    V.resize(unique(V.begin(), V.end()) - V.begin());
    for (int i = 0; i < N; i++)
        a[i] = lower_bound(V.begin(), V.end(), a[i]) - V.begin();
        
    for (int i = 0; i < N; i++)
        E[a[i]].push_back(i);
    
    compute(S, 0);
    for (int i = 0; i < N; i++) 
        compute(i, a[i] + 1);
        
    memset(dp[0], INF, sizeof dp[0]);
           
    int c = 0;  
    dp[0][S] = 0;  
    for (int i = 0; i < N; i++) {
        if (E[i].empty()) continue;
        c ^= 1;
        memset(dp[c], INF, sizeof dp[c]);
        for (int j = 0; j < E[i].size(); j++) 
            for (int k = 0; k < N; k++) {
                int tmp = dp[c ^ 1][k] + trans[k][E[i][j]];
                if (tmp < dp[c][E[i][j]]) {
                    dp[c][E[i][j]] = tmp;
                    dad[E[i][j]] = k;
                }
            }
    }    
    
    int fin = min_element(dp[c], dp[c] + N) - dp[c]; 
    printf("%d\n", dp[c][fin]);
    
    vector <int> path;
    for (int i = 0; i < V.size(); i++) {
        path.push_back(fin);
        fin = dad[fin];
    }
    path.push_back(S);
    
    reverse(path.begin(), path.end());
    for (int i = 1; i < path.size(); i++) 
        reconstruct(path[i - 1], path[i]);
}

int main() {
    load();
    solve();
    return 0;
}