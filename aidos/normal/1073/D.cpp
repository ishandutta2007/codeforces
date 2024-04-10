#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)4e5 + 10;
const int mod = (int)998244353 ;
const int inf = (1<<30) - 1;
int n;
ll T;
ll a[maxn];
void solve(){
    cin >> n >> T;
    ll s = 0;
    vector<ll> d;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        s += a[i];
        d.emplace_back(a[i]);
    }
    ll ans = 0;
    ll c = T/s;
    T %= s;
    ans += c * n;
    while(d.size() > 0) {
        vector<ll> c;
        ll s = 0;
        for(int i = 0; i < d.size(); i++) {
            if(d[i] <= T) {
                T-=d[i];
                c.emplace_back(d[i]);
                s += d[i];
                ans++;
            }
        }
        d = c;
        if(s > 0) {
            ans += T/s * d.size();
            T %= s;
        }
    }
    cout << ans << "\n";
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
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