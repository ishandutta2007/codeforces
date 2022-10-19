#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std; 

const int MAXM = 205;
const int MAXN = 40005;
const int MAXL = 1000005;

int N, M, Q;
char mat[MAXM][MAXM];
char s[MAXL];
int a[15], b[15];
int who[MAXN];
char num[MAXN];
vector <int> ch[MAXN];
vector <int> roots;
int bio[MAXN];
int cyc[MAXN];
int mask[MAXN];
int cnt;

void load() {
    scanf("%d%d%d", &N, &M, &Q);
    for (int i = 0; i < N; i++)
        scanf("%s", mat[i]);
    for (int i = 0; i < 10; i++)
        scanf("%d%d", a + i, b + i);
}

int get(int x, int y) {
    if (x < 0 || y < 0 || x >= N || y >= M) return -1;
    return x * M + y;
}

void remove(int node, int child) {
    for (int i = 0; i < ch[node].size(); i++)
        if (ch[node][i] == child) {
            ch[node].erase(ch[node].begin() + i);
            break;
        }
}

void dfs(int x) {
    vector <int> V, tmp;
    for (; x != -1 && !bio[x]; x = who[x]) {
        V.push_back(x);
        bio[x] = 1;
    }
    tmp = V;
    
    if (x != -1 && bio[x] == 1) {
        cnt++;
        vector <int> curr;
        curr.push_back(x);
        for (; V.back() != x; V.pop_back()) 
            curr.push_back(V.back());
        int sz = curr.size();
        for (int i = 0; i < sz; i++) {
            remove(curr[i], curr[(i + 1) % sz]);
            cyc[curr[i]] = cnt;
            roots.push_back(curr[i]);
            mask[cnt] |= 1 << num[curr[i]] - '0';
        }
    }
    
    for (int i = 0; i < tmp.size(); i++)
        bio[tmp[i]] = 2;
}

int rec(int x) {
    int res = -1;
    for (int i = 0; i < ch[x].size(); i++)
        res = max(res, rec(ch[x][i]));
    res += s[res + 1] == num[x];
    return res; 
}

bool match(int node) {
    for (int i = rec(node) + 1; s[i]; i++)
        if (!(mask[cyc[node]] >> s[i] - '0' & 1)) return false;
    return true;
}

void solve() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            int tmp = get(i, j);
            num[tmp] = mat[i][j];
            who[tmp] = get(i + a[num[tmp] - '0'], j + b[num[tmp] - '0']);
            if (who[tmp] == -1) who[tmp] = tmp;
            ch[who[tmp]].push_back(tmp);
        }
    
    N *= M;
    for (int i = 0; i < N; i++)
        dfs(i);
    
    while (Q--) {
        scanf("%s", s);
        bool ok = false;
        for (int i = 0; i < roots.size(); i++)
            ok |= match(roots[i]);
        puts(ok ? "YES" : "NO");
    }    
}

int main() {
    load();
    solve();
    return 0;
}