#pragma optimize("", on)
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n, k;
string s, t, ans;
void solve() {
    cin >> s >> n;
    for(int i = 0; i < n; i++) {
        cin >> t;
        if(t.size() < s.size()) continue;
        if(t.substr(0, s.size()) == s) {
            if(ans.size() == 0) ans = t;
            else ans = min(ans, t);
        }
    }
    if(ans.size() == 0) ans = s;
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