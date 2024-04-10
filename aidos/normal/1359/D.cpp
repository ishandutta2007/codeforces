#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxm = (int)1e7 + 100;
const int maxn = (int) 5e5 + 100;
int a[maxn];
int pref[maxn];
int suf[maxn];
int n;
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for(int x = -30; x <= 30; x++) {
        int mi = 0;
        int sum = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] > x) {
                sum = 0;
                mi = 0;
                continue;
            }
            pref[i] = sum - mi;
            sum += a[i];
            mi = min(sum, mi);
        }
        mi = 0;
        sum = 0;
        for(int i = n-1; i >= 0; i--) {
            if(a[i] > x) {
                sum = 0;
                mi = 0;
                continue;
            }
            suf[i] = sum - mi;
            sum += a[i];
            mi = min(sum, mi);
        }
        for(int i = 0; i < n; i++) {
            if(a[i] == x) {
                ans = max(ans, pref[i] + suf[i]);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}