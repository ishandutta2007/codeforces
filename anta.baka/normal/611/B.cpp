#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()

const int a[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    ll l, r; cin >> l >> r;
    int ans = 0;
    for(int len = 2; len <= 62; len++) {
        ll a = (1LL << len) - 1;
        //cout << a << endl;
        for(int i = 0; i < len - 1; i++) {
            ll b = a - (1LL << i);
            ans += (l <= b && b <= r);
        }
    }
    cout << ans;
}