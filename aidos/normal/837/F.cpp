#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
const double pi = acos(-1);
ll n, k;
int a[200200];
void solve() {
    cin >> n >> k;
    vector<ll> c;
    c.push_back(0);
    for(int i = 0; i < n; i++) {
        int x;
        cin>>x;
        if(x == 0 && c.size() == 1) continue;
        c.push_back(x);
    }
    if(*max_element(c.begin(), c.end()) >= k) {
        cout << 0 << "\n";
        return;
    }
    if(c.size() > 4) {
        int cnt = 0;
        while(*max_element(c.begin(), c.end()) < k) {
            for(int i = 1; i < c.size(); i++) {
                c[i] += c[i-1];
            }
            cnt++;
        }
        cout << cnt << "\n";
        return;
    }
    if(c.size() == 3) {
        ll a = c[1];
        ll b = c[2];
        cout << (k-b + a-1)/a << "\n";
        return;
    }
    ll l = 1, r = min(k, (ll)2e9), res = -1;
    while(l <= r) {
        ll mid = (l + r)/2;
        ll K = k-c[3];
        if(c[2] * mid >= K) {
            res = mid;
            r = mid-1;
            continue;
        }
        K -= c[2] * mid;
        ll val = mid * (mid+1)/2;
        if(K/c[1] < val || K <= val * c[1]) {
            res = mid;
            r = mid-1;
        }else {
            l = mid+1;
        }
    }
    cout << res << "\n";
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}