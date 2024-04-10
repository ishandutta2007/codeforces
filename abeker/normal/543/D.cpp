#include <cstdio>
#include <vector>
using namespace std;

const int MAXN = 200005;
const int MOD = 1000000007;

int N;
int p[MAXN];
vector <int> ch[MAXN];
int dp[MAXN], sol[MAXN];

inline int mul(int x, int y) {
    return (long long)x * y % MOD;
}

inline int inc(int x) {
    return x < MOD - 1 ? x + 1 : 0;
}

void load() {
    scanf("%d", &N);
    for (int i = 2; i <= N; i++) {
        scanf("%d", p + i);
        ch[p[i]].push_back(i);
    }
}

void dfs(int x) {
    sol[x] = 1;
    for (int i = 0; i < ch[x].size(); i++) {
        int nxt = ch[x][i];
        dfs(nxt);
        sol[x] = mul(sol[x], inc(sol[nxt]));
    }
}

void calc(int x) {
    int sz = ch[x].size();
    vector <int> pref, suff;
    pref.push_back(1);
    for (int i = 0; i < sz; i++) 
        pref.push_back(mul(pref.back(), inc(sol[ch[x][i]])));
    
    suff.resize(sz + 1);
    suff[sz] = 1;
    for (int i = sz - 1; i >= 0; i--)
        suff[i] = mul(suff[i + 1], inc(sol[ch[x][i]]));
        
    for (int i = 0; i < sz; i++) 
        dp[ch[x][i]] = inc(mul(mul(pref[i], suff[i + 1]), dp[x]));
    
    for (int i = 0; i < sz; i++)
        calc(ch[x][i]);
}

void solve() {
    dp[1] = 1;
    dfs(1);
    calc(1);
    for (int i = 1; i <= N; i++)
        printf("%d ", mul(dp[i], sol[i]));
    puts("");
}

int main() {
    load();
    solve();
    return 0;
}