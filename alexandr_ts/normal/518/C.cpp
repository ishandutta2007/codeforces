#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, n) for (int i = a; i < b; i++)

using namespace std;

typedef long long ll;

const ll N = 1e6 + 1;

ll a[N], mp[N];

int main() {
    ll n, m, k;
    cin >> n >> m >> k;
    fr(i, n) {
        cin >> a[i + 1];
        mp[a[i + 1]] = i + 1;
    }
    ll t, ans = 0;
    fr(i, m) {
        cin >> t;
        ans += (mp[t] - 1) / k;
        if (mp[t] > 1) {
            swap(a[mp[t]], a[mp[t] - 1]);
            swap(mp[a[mp[t]]], mp[a[mp[t] - 1]]);
        }
    }
    cout << ans + m;
}