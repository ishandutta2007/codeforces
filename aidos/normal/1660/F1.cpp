#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 100;
typedef long long ll;
int n, k;
ll a[maxn];
int pref[maxn];
void solve() {
    cin >> n;
    string s;
    cin >> s;
    for(int i = 1; i <= n; i++) {
        pref[i] = pref[i-1];
        if(s[i-1] == '+') {
            pref[i]--;
        } else {
            pref[i]++;
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            int x = pref[i] - pref[j-1];
            if(x >= 0 && x % 3 == 0) {
                ans++;
            }
        }
    }
    cout << ans << "\n";
}




int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    int t=1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
}