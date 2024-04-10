#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define sz(a) (int)(a).size()
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

int binpow(int a, int n, int mod) {
    int ans = 1;
    while (n) {
        if (n & 1) {
            ll x = ll(ans) * ll(a);
            x %= mod;
            ans = x;
        }
        n >>= 1;
        ll x = ll(a) * ll(a);
        x %= mod;
        a = x;
    }
    return ans;
}

int mod;

const int nmax = int(1e6) + 100500;

int fact[nmax], rfact[nmax];

void mul(int& a, int b) {
    ll c = ll(a) * b;
    if (c >= mod) {
        c %= mod;
    }
    a = c;
}

void add(int& a, int b) {
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}

int binpow(int a, int n) {
    int ans = 1;
    while (n) {
        if (n & 1) {
            mul(ans, a);
        }
        n >>= 1;
        mul(a, a);
    }
    return ans;
}

int sum[nmax];

int bin(int n, int k) {
    assert(k <= n);
    int ans = fact[n];
    mul(ans, rfact[k]);
    mul(ans, rfact[n - k]);
    return ans;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("input.txt");

    int n, m, a, q;
    cin >> n >> m >> a >> q;

    int p = 1;
    ll curr = a % q;
    while (curr != 1) {
        curr *= ll(a);
        curr %= q;
        ++p;
    }

    mod = p;

    fact[0] = rfact[0] = 1;
    for (int i = 1; i < nmax; ++i) {
        fact[i] = fact[i - 1];
        mul(fact[i], i);
        rfact[i] = binpow(fact[i], mod - 2);
    }

    sum[0] = 1;
    for (int i = 1; i <= m; ++i) {
        sum[i] = sum[i - 1];
        add(sum[i], bin(m, i));
    }

    for (int i = 0; i < n; ++i) {
        int k = min(n - i - 1, m);
        int deg = sum[k];
        cout << binpow(a, deg, q) << " ";
    }
    cout << "\n";

}