#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

ll f(ll n, ll k) {
    if (1ll << (n - 1) == k)
        return n;
    if (1ll << (n - 1) > k)
        return f(n - 1, k);
    return f(n - 1, k - (1ll << (n - 1)));
}

int main() {
    //freopen("a.in", "r", stdin);
    ll n, k;
    cin >> n >> k;
    cout << f(n, k);
}