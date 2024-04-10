#include <bits/stdc++.h>
using namespace std;
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
using ll = long long;
const int mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    int n, k; cin >> n >> k;
    int sub = 0;
    ll s = 0;
    for(int i = 1; i <= n; i++) {
        ll x; cin >> x;
        if(s - ((i - sub) - 1) * ((n - sub) - (i - sub)) * x < k) {
            sub++;
            cout << i << '\n';
        } else s += x * ((i - sub) - 1);
    }
}