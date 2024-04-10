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
int n;
void solve() {
    string s;
    cin >> s;
    vector<string> ans;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] != '0') {
            string t = string(s.size()-i-1, '0');
            t = s[i] + t;
            ans.emplace_back(t);
        }
    }
    cout << ans.size() << "\n";
    for(int i = 0; i<ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
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