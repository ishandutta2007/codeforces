#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];
int b[maxn];

void solve() {
    string s, t;
    cin >> s >> t;
    int ans = s.size() + t.size();
    for(int len=1; len <= s.size() && len <= t.size(); len++) {
        int ok = 0;
        for(int i = 0; i + len -1 < s.size(); i++) {
            for(int j = 0; j + len - 1 < t.size(); j++) {
                if(s.substr(i, len) == t.substr(j, len)) {
                    ok = 1;
                }
            }
        }
        ans -= 2*ok;
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