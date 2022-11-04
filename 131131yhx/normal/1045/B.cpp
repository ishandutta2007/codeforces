#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

#define int long long
#define P 999999999999947
#define mul 233
using namespace std;

typedef long long ll;

int n, M, A[400010];

ll powmod(ll x, ll y, ll p = P) {
    ll ans = 1;
    while(y) {
        if(y & 1) ans = ans * x % p;
        x = x * x % p;
        y >>= 1;
    }
    return ans;
}

bool vis[200010];

int tmpA1, B[400010], C[400010], Pr[400010];

vector <int> Ans;

signed main() {
    scanf("%lld%lld", &n, &M);
    for(int i = 1; i <= n; i++) scanf("%lld", &A[i]);
    tmpA1 = A[1];
    for(int i = 1; i <= n; i++) A[i] -= tmpA1;
    for(int i = 2; i <= n; i++) B[i - 1] = A[i] - A[i - 1];
    B[n] = M - A[n];
    int t = 0;
    for(int i = n - 1; i >= 1; i--) C[++t] = B[i];
    for(int i = n; i >= 1; i--) C[++t] = B[i];
    int s = 0;
    for(int i = 2; i <= n; i++) {
        while(s && B[s + 1] != B[i]) s = Pr[s];
        s++;
        Pr[i] = s;
    }
    s = 0;
    for(int i = 1; i < n * 2; i++) {
        while(s && B[s + 1] != C[i]) s = Pr[s];
        if(B[s + 1] == C[i]) s++;
        if(s == n) {
            Ans.push_back((tmpA1 * 2 + A[n * 2 - i]) % M);
            s = Pr[s];
        }
    }
    sort(Ans.begin(), Ans.end());
    if(Ans.size()) {
        printf("%d\n", Ans.size());
        for(int i = 0; i < Ans.size(); i++) printf("%lld ", Ans[i]);
        putchar('\n');
        return 0;
    } else puts("0");
}