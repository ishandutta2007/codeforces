#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

//#define debug(x) ;
#define debug(x) cerr << #x << " = " << x << "\n";

ostream& operator<<(ostream& cerr, vector<ll> aux) {
    cerr << "[";
    for (auto e : aux) cerr << e << ' ';
    cerr << "]";
    return cerr;
}

const int maxN = 300011;
const int limit = 300000;
const ll mod = 1000000007;

int n, i, j, ans, all;
int a[maxN];

bool deny[maxN], not_prime[maxN];
int sgn[maxN];
int cnt[maxN];
vector<int> verif;
ll fact[maxN], inv_fact[maxN];

ll poww(ll a, ll b) {
    ll ans = 1;
    while (b > 0) {
        if (b & 1) ans = (ans * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }
    return ans;
}

int gcd(int x, int y) {
    if (x < y) swap(x, y);
    while (y > 0) {
        x %= y;
        swap(x, y);
    }
    return x;
}

ll comb(ll n, ll k) {
    if (k > n) return 0;
    ll ans = (fact[n] * inv_fact[k]) % mod;
    ans = (ans * inv_fact[n - k]) % mod;
    return ans;
}

void pre() {
    ll i, j;

    for (i = 2; i <= limit; i++)
        for (j = 2 * i; j <= limit; j += i)
            cnt[i] += cnt[j];

    for (i = 2; i <= limit; i++) {
        if (deny[i]) continue;
        verif.pb(i);

        if (not_prime[i]) continue;
        
        for (j = i; j <= limit; j += i) {
            sgn[j] ^= 1;
            not_prime[j] = true;
        }
        for (j = i * i; j <= limit; j += i * i)
            deny[j] = true;
    }

    fact[0] = 1;
    for (i = 1; i <= n; i++)
        fact[i] = (fact[i - 1] * i) % mod;

    inv_fact[n] = poww(fact[n], mod - 2);
    for (i = n - 1; i >= 0; i--)
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % mod;
}

bool check(int sel) {
    ll need = comb(n, sel);

    for (auto e : verif) {
        if (cnt[e] > 0)
            //cerr << e << ' ' << cnt[e] << ' ' << sgn[e] << ' ' << need << '\n';
        if (sgn[e] == 1) {
            need += mod - comb(cnt[e], sel);
        } else {
            need += comb(cnt[e], sel);
        }
    }
    
    return (need % mod != 0);
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        cnt[a[i]]++;
    }

    all = a[1];
    for (i = 2; i <= n; i++)
        all = gcd(all, a[i]);
    if (all != 1) {
        printf("-1");
        return 0;
    }

    pre();
    for (i = 1; check(i) == false; i++);
    printf("%d", i);


    return 0;
}