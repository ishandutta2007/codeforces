#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
const int maxn = 2e6 + 1;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    ll n; cin >> n;
    ll ans = 0;
    for(int i = 0; n != 1; i++) {
        ans += (1LL << i) * (n / 2);
        n = (n + 1) / 2;
    }
    cout << ans;
}