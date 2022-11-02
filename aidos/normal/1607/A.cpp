#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;

void solve(){
    string s, t;
    cin >> t >> s;
    map<int, int> m;
    for(int i = 0; i < t.size(); i++) m[t[i]] = i;
    int ans = 0;

    for(int i = 1; i < s.size(); i++) {
        int d = m[s[i]];
        d -= m[s[i-1]];
        ans += abs(d);
    }
    cout << ans << "\n";
}





int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
}