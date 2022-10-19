#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair <ll, int> pii;

const int MAXN = 1005;
const int MAXD = 10005;
const int INF1 = 0x3f3f3f3f;
const int INF2 = 0x3f3f3f3f3f3f3f3fll;

int N;
ll K;
ll a[MAXN];
vector <pii> f;
vector <int> d[MAXD];
vector <int> exp[MAXN];
int dp[MAXN][MAXD];
ll sum[2][MAXD];
pii dad[MAXN][MAXD];

void load() {
    scanf("%d%I64d", &N, &K);
    for (int i = 1; i <= N; i++)
        scanf("%I64d", a + i);
}

int get(ll &x, ll p) {
    int res = 0;
    for (; !(x % p); x /= p)
        res++;
    return res;
}

void factor(ll x) {
    for (ll i = 2; i * i <= x; i++) 
        if (!(x % i)) 
            f.push_back(pii(i, get(x, i)));
    if (x > 1) f.push_back(pii(x, 1));
}

void solve() {
    if (K == 1) {
        printf("1\n%d\n", min_element(a + 1, a + N + 1) - a);
        return;
    }
    
    factor(K);
    
    for (int i = 1; i <= N; i++) {
        ll memo = a[i];
        for (int j = 0; j < f.size(); j++)
            exp[i].push_back(get(a[i], f[j].first));
        a[i] = memo;
    }
    
    int tot = 1;
    for (int i = 0; i < f.size(); i++) 
        tot *= f[i].second + 1;
    
    for (int i = 0; i < tot; i++) {
        int x = i;
        for (int j = 0; j < f.size(); j++) {
            d[i].push_back(x % (f[j].second + 1));
            x /= f[j].second + 1;
        }
    }
    
    int c = 0;
    for (int i = 1; i < tot; i++) {
        dp[0][i] = INF1;
        sum[c][i] = INF2;
    }
    
    for (int i = 1; i <= N; i++) {
        c ^= 1;
        for (int j = 0; j < tot; j++) {
            dp[i][j] = INF1;
            sum[c][j] = INF2;
            int p = dp[i - 1][j];
            ll u = sum[c ^ 1][j];
            int tmp = 0, prod = 1;
            for (int k = 0; k < f.size(); k++) {
                tmp += max(d[j][k] - exp[i][k], 0) * prod;
                prod *= f[k].second + 1;
            }   
            int q = dp[i - 1][tmp] + 1;
            ll v = sum[c ^ 1][tmp] + a[i]; 
            if (p < q || (p == q && u < v)) {
                dp[i][j] = p;
                dad[i][j] = pii(i - 1, j);                             
                sum[c][j] = u;
            }            
            if (p > q || (p == q && u >= v)) {
                dp[i][j] = q;
                dad[i][j] = pii(i - 1, tmp);
                sum[c][j] = v;
            }
        }
    }
    
    if (dp[N][tot - 1] > N) {
        puts("-1");
        return;
    }
    
    printf("%d\n", dp[N][tot - 1]);
    pii curr(N, tot - 1);
    while (curr.first) {
        pii nxt = dad[curr.first][curr.second];
        if (nxt.second != curr.second)
            printf("%d ", curr.first);
        curr = nxt;
    }
    puts("");
}

int main() {
    load();
    solve();
    return 0;
}