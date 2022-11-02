#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n;
int a[maxn];
ll cnt[maxn];
void solve() {
   cin >> n;
   for(int i = 0; i <= 30; i++) cnt[i] = 0;
   for(int i = 0; i < n; i++) {
       cin >> a[i];
       int bit = 30;
       while(!(a[i] & (1<<bit))) bit--;
       cnt[bit]++;
   }

   ll ans = 0;
   for(int i = 0; i <= 30; i++) ans += cnt[i] * (cnt[i] - 1)/2;
   cout << ans << "\n";
}
int main() {
    int t = 1;
    //scanf("%d", &t);
    cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}