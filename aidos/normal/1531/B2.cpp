#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 1e5 + 100;
int n;
ll w, h;
void solve() {
   cin >> n;
   map<ll, ll> cnt;
   map< pair<ll, ll>, int> cnt2;
   ll ans = 0;
   for(int i = 0; i < n; i++) {
       cin >> h >> w;
       if(h > w) swap(h, w);
       if(h == w) {
           ans += cnt[h];
           cnt[h]++;
       }
       else {
           ans += cnt[h];
           ans += cnt[w];
           ans -= cnt2[make_pair(h, w)];
           cnt[h]++;
           cnt[w]++;
           cnt2[make_pair(h, w)]++;
       }
   }
   cout << ans << "\n";
}

int main() {
    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d:\n", i);
        solve();
    }

    return 0;
}