#include <cstdio>
#include <vector>
using namespace std;

const int MAXN = 100005;
const int MOD = 1000000007;

int N;
int a[MAXN];    
vector <int> ch[MAXN];
int dp[MAXN][2];

inline int add(int x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
    return x;
}

inline int mul(int x, int y) {
    return (long long)x * y % MOD;
}

void load() {
    scanf("%d", &N);
    for (int i = 1; i < N; i++) {
        int x;
        scanf("%d", &x);
        ch[x].push_back(i);
    }
    for (int i = 0; i < N; i++)
        scanf("%d", a + i);
}

int dfs(int x) {
    vector <int> tmp;
    for (int i = 0; i < ch[x].size(); i++) 
        tmp.push_back(dfs(ch[x][i]));
    
    int prod = 1, sz = tmp.size();
    for (int i = 0; i < sz; i++)
        prod = mul(prod, tmp[i]);
        
    if (a[x]) 
        dp[x][1] = prod;
    else {
        dp[x][0] = prod;
        vector <int> suff(sz + 1);
        suff[sz] = 1;
        for (int i = sz - 1; i >= 0; i--)
            suff[i] = mul(suff[i + 1], tmp[i]);
        prod = 1;
        for (int i = 0; i < sz; i++) {
            dp[x][1] = add(dp[x][1], mul(mul(prod, suff[i + 1]), dp[ch[x][i]][1]));
            prod = mul(prod, tmp[i]);
        }
    }
    
    return add(dp[x][0], dp[x][1]);
}

int solve() {
    dfs(0);
    return dp[0][1];
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}