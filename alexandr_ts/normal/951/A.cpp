#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int N = (int)1e6 + 34;
const int INF = (int)1e9 + 41;
//const ll INF = (ll)1e18 + 41;

void solve() {
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    s += s;
    int ans = 0;
    int cur = 0;
    for (int i = 0; i < s.size(); i++) {
        if (i == 0 || s[i] != s[i - 1])
            cur++;
        else
            cur =1 ;
        ans = max(ans, cur);
    }
    cout << min((int)s.size() / 2, ans);
}

int main() {
#ifdef KEK
    //freopen("a.in", "r", stdin);
    //solve();
#endif // KEK
    solve();
}