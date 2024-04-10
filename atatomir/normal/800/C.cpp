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

#define maxN 200011

int n, mod, i, x;
bool off[maxN];
vector<int> who[maxN], divs[maxN];
ll phi;

int dp[maxN], from[maxN];
vector<ll> ord, ans;

int gcd(int x, int y) {
    if (x < y) swap(x, y);
    while (y > 0) {
        x %= y;
        swap(x, y);
    }
    return x;
}

void pre() {
    ll i, j;
    phi = mod;

    for (i = 2; i <= mod; i++) {
        if (divs[i].size()) continue;

        if (mod % i == 0) {
            phi /= i;
            phi *= i - 1;
        }

        for (j = i; j <= mod; j += i)
            divs[j].pb(i);
    }



}

ll poww(ll a, ll b) {
    ll ans = 1;

    while (b > 0) {
        if (b & 1) ans = (ans * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }

    return ans;
}

void add_element(ll old_val, ll new_val) {
    ll d = gcd(old_val, mod);
    ll inv = poww(old_val / d, phi - 1);

    ans.pb( (inv * (new_val / d)) % mod );
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &mod);
    for (i = 1; i <= n; i++) {
        scanf("%d", &x);
        off[x] = true;
    }

    for (i = 0; i < mod; i++) {
        if (off[i]) continue;
        who[ gcd(i, mod) ].pb(i);
    }

    pre();

    int aux;
    for (i = 1; i <= mod; i++) {
        dp[i] = who[i].size();
        from[i] = i;

        for (auto e : divs[i]) {
            aux = i / e;
            if (dp[aux] + who[i].size() > dp[i]) {
                dp[i] = dp[aux] + who[i].size();
                from[i] = aux;
            }
        }
    }

    int pos = mod;
    while(1) {
        for (auto e : who[pos]) ord.pb(e);

        if (pos == from[pos]) break;
        pos = from[pos];
    }

    reverse(ord.begin(), ord.end());
    ans = {ord[0]};

    for (i = 1; i < ord.size(); i++) add_element(ord[i - 1], ord[i]);

    printf("%d\n", ans.size());
    for (auto e : ans) printf("%lld ", e);

    /*cerr << "\n\n!\n";
    for (i = 1; i < ans.size(); i++) ans[i] = (ans[i] * ans[i - 1]) % mod;
    for (auto e : ans) cerr << e << ' ';

    cerr << "\n\n!\n";
    for (auto e : ord) cerr << e << ' ';*/



    return 0;
}