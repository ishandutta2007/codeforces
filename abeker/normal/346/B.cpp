#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

const int MAXN = 105;
const int INF = 0x3f3f3f3f;

struct state {
    int f, s, t;    
    state(int f, int s, int t) : f(f), s(s), t(t) {}
    state() : f(0), s(0), t(0) {}
};

int N, M, K;
char a[MAXN], b[MAXN], c[MAXN];
int len[MAXN][30];
int dp[MAXN][MAXN][MAXN];
state nxt[MAXN][MAXN][MAXN];

void load() {
    scanf("%s%s%s", a, b, c);
}

int rec(int x, int y, int z) {
    int &ref = dp[x][y][z];
    state &w = nxt[x][y][z];
    if (ref != -INF) return ref;
    int p = rec(x + 1, y, z);
    if (p > ref) { ref = p; w = state(x + 1, y, z); }
    p = rec(x, y + 1, z);
    if (p > ref) { ref = p; w = state(x, y + 1, z); }
    if (a[x] == b[y]) {
        p = rec(x + 1, y + 1, len[z][a[x] - 'A']) + 1;
        if (p > ref) { ref = p; w = state(x + 1, y + 1, len[z][a[x] - 'A']); }
    }
    return ref;
}

int calc(string x, string y) {
    for (int i = 0; i < x.size(); i++)
        if (x.size() - i <= y.size() && x.substr(i, x.size() - i) == y.substr(0, x.size() - i))
            return x.size() - i;
    return 0;
}

void solve() {
    int N = strlen(a);
    int M = strlen(b);
    int K = strlen(c);
    for (int i = 0; i < K; i++)     
        for (int l = 0; l < 26; l++) {
            string s = "";
            for (int j = 0; j < i; j++)
                s += c[j];
            s += (char)('A' + l);
            len[i][l] = calc(s, c);
        }
        
    for (int i = 0; i <= N; i++)
        for (int j = 0; j <= M; j++)
            for (int k = 0; k <= K; k++) {
                dp[i][j][k] = -INF;
                if (k == K) dp[i][j][k] -= 5;
                else if (i == N || j == M) dp[i][j][k] = 0;
            }
    
    int res = rec(0, 0, 0);
    if (!res) {
        puts("0");
        return;
    }
    
    state curr(0, 0, 0);
    while (res) {
        state st = nxt[curr.f][curr.s][curr.t];
        if (st.f > curr.f && st.s > curr.s) {
            putchar(a[curr.f]);
            res--;
        } 
        curr = st;
    }
    puts("");
}

int main() {
    load();
    solve();
    return 0;
}