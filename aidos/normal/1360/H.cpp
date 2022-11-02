#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
const double pi = acos(-1);
int n, m;

void solve() {
    vector<ll> a;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        ll x = 0;
        for(const char &c: s) {
            x = x * 2 + c - '0';
        }
        a.emplace_back(x);
    }
    sort(a.begin(), a.end());
    ll l = 0, r = (1ll<<m)-1;
    ll k = (1ll<<m) - n - 1;
    ll res = -1;
    while(l <= r) {
        ll mid = (l + r)/2;
        int pos = upper_bound(a.begin(), a.end(), mid) - a.begin();
        if(mid - pos < k/2) {
            l = mid + 1;
        }else {
            r = mid - 1;
            res = mid;
        }
    }
    for(int i = m-1; i >= 0; i--) {
        if(res & (1ll<<i)) cout << 1;
        else cout << 0;
    }
    cout << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}