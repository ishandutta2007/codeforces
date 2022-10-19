#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 30005;

int N, M, P, G;
int a[MAXN];
vector <pii> f;
vector <int> d;
vector <int> E[MAXN];
int dp[MAXN];
int phi[MAXN];

void load() {
    scanf("%d%d%d", &N, &M, &P);
    for (int i = 0; i < N; i++)
        scanf("%d", a + i);
    G = P - 1;
    while (M--) {
        int b;
        scanf("%d", &b);
        G = __gcd(G, b);
    }
}

inline int mul(int x, int y) {
    return (long long)x * y % P;
}

int pow(int x, int y) {
    int res = 1;
    for (; y; y >>= 1) {
        if (y & 1) res = mul(res, x);
        x = mul(x, x);
    }
    return res;
}

int order(int x) {
    int res = 1;
    for (int i = 0; i < f.size(); i++) {
        int tmp = P - 1;
        for (int j = 0; j < f[i].second; j++)
            tmp /= f[i].first;
        int curr = pow(x, tmp);
        for (; curr != 1; curr = pow(curr, f[i].first))
            res *= f[i].first;
    }
    return res;
}

vector <pii> factor(int x) {
    vector <pii> res;
    for (int i = 2; i * i <= x; i++) {
        if (x % i) continue;
        int cnt = 0;
        for (; !(x % i); x /= i)    
            cnt++;
        res.push_back(pii(i, cnt));
    }
    if (x > 1) res.push_back(pii(x, 1));
    return res;
}

vector <int> divisors(int x) {
    vector <int> res;
    for (int i = 1; i * i <= x; i++) {
        if (x % i) continue;
        res.push_back(i);
        if (i * i < x) res.push_back(x / i);
    }
    sort(res.begin(), res.end());
    return res;
}

int get(int x) {
    return lower_bound(d.begin(), d.end(), x) - d.begin(); 
}

int dfs(int x) {
    if (dp[x] != -1)    
        return dp[x];
    dp[x] = 0;
    for (int i = 0; i < E[x].size(); i++)
        dp[x] |= dfs(E[x][i]);
    return dp[x];
}

int solve() {
    if (P == 2) return 1;
    
    for (int i = 0; i < N; i++)
        a[i] = pow(a[i], G);
        
    f = factor(P - 1);
    d = divisors(P - 1);
    
    for (int i = 0; i < d.size(); i++) {
        phi[i] = d[i]; 
        for (int j = 0; j < f.size(); j++) {
            if (d[i] % f[j].first) continue; 
            E[i].push_back(get(d[i] / f[j].first));
            phi[i] /= f[j].first;
            phi[i] *= f[j].first - 1;
        }
    }
                
    memset(dp, -1, sizeof dp);
    for (int i = 0; i < N; i++) 
        dp[get((P - 1) / order(a[i]))] = 1;
    
    int sol = 0;
    for (int i = 0; i < d.size(); i++)
        if (dfs(i)) sol += phi[(int)d.size() - i - 1];
    
    return sol;         
}
 
int main() {
    load();
    printf("%d\n", solve());
    return 0;
}