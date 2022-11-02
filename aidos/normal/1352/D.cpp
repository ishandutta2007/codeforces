#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e5 + 10;
const int mod = 998244353;
const int inf = (1<<30) - 1;
const double pi = acos(-1);
const double eps = 1e-15;
int n, k;
int a[maxn];
void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int l = 0, r = n-1;
    int last = 0;
    int cnt = 0;
    int x = 0, y = 0;
    while(l <= r) {
        cnt++;
        if(cnt & 1) {
            int cur = 0;
            while(l <= r && cur <= last) {
                cur += a[l];
                l++;
            }
            last = cur;
            x += cur;
        } else {
            int cur = 0;
            while(l <= r && cur <= last) {
                cur += a[r];
                r--;
            }
            last = cur;
            y += cur;
        }
    }
    cout << cnt <<" " << x << " " << y << "\n";
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