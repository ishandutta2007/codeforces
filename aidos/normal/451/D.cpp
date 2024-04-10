#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxm = (int)1e7 + 100;
const int maxn = (int) 3e5 + 100;
const int mod = (int)998244353 ;
int n, r;
string s;
map<pair<int, char>, int> m;
void solve() {
    cin >> s;
    long long ans1 = 0;
    long long ans2 = 0;
    for(int i = 0; i < s.size(); i++) {
        m[make_pair(i % 2, s[i])]++;
        ans2 += m[make_pair(i % 2, s[i])];
        ans1 += m[make_pair(1-i % 2, s[i])];
    }
    cout << ans1 << " " << ans2 << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    for(int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}