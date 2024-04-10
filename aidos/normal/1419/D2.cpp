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
int b[maxn];

bool can(int x) {
    int l = 0;
    int r = n - 1;
    for(int i = 0; i < x; i++) {
        b[i * 2 + 1] = a[l++];
    }
    for(int i = x; i >= 0; i--) {
        b[i * 2] = a[r--];
    }
    for(int i = 2 * x + 1; i < n; i++) {
        b[i] = a[l++];
    }
    int cnt = 0;
    for(int i = 1; i + 1 < n; i++) {
        if(b[i] < b[i-1] && b[i]<b[i+1]) {
            cnt++;
        }
    }
    return cnt >= x;
}
void solve() {
   cin >> n;
   for(int i = 0; i < n; i++) cin >> a[i];
   sort(a, a + n);
   int l = 0, r = (n-1)/2;
   int res = 0;
   while(l <= r) {
       int mid = (l + r)/2;
       if(can(mid)) {
           res=mid;
           l = mid + 1;
       } else {
           r = mid - 1;
       }
   }
   assert(can(res));
   cout << res << "\n";
   for(int i = 0; i < n; i++) cout << b[i] << " ";
}
int main() {
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}