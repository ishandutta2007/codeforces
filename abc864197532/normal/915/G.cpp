#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pii pair<int,int>
#define pdd pair<ld,ld>
#define ld double
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
#define oset tree<lli,null_type,less<lli>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 2000001, logN = 17;

lli modpow(lli a, int b) {
    lli ans = 1;
    for (; b; b >>= 1, a = a * a % mod) {
        if (b & 1) ans = ans * a % mod;
    }
    return ans;
}

vector <int> lastPrime (int n) {
    vector <int> ans(n + 1, 0), prime;
    for (int i = 2; i <= n; ++i) {
        if (!ans[i]) {
            prime.push_back(i);
            ans[i] = i;
        }
        for (int j = 0; 1ll * prime[j] * i <= n; j++) {
            ans[prime[j] * i] = prime[j];
            if (i % prime[j] == 0) break;
        }
    }
    return ans;
}

vector <int> get_mu (int n) {
    vector<int> LPrime = lastPrime(n), mobius(n + 1);
    mobius[1] = 1;
    for (int i = 2; i <= n; ++i) {
        if (LPrime[i] == LPrime[i / LPrime[i]]) mobius[i] = 0;
        else mobius[i] = mobius[i / LPrime[i]] * -1;
    }
    return mobius;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector <int> mu = get_mu(N + 1);
    vector <int> pr[N];
    fop (i,1,N) for (int j = i; j < N; j += i) if (mu[i]) pr[j].pb(i);
    int n, k;
    cin >> n >> k;
    lli ans = 0, now = 1;
    vector <lli> cur(k + 1, 0);
    lli p[k + 1];
    fop (i,0,k + 1) p[i] = modpow(i, n);
    cur[1] = 1;
    fop (i,2,k + 1) {
        for (int j : pr[i]) {
            now = (now - cur[j] * mu[j]) % mod;
            cur[j] = p[i / j];
            now = (now + cur[j] * mu[j]) % mod;
        }
        if (now < 0) now += mod; 
        ans = (ans + (now ^ i)) % mod;
    }
    cout << ans << endl;
}