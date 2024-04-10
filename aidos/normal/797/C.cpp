#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int) 2e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1 << 30) - 1;
const double pi = acos(-1);
const double eps = 1e-15;
string s;
int dp[maxn];
void solve() {
    cin >> s;
    int n = s.size();
    dp[n] = inf;
    for(int i = n-1; i>=0; i--) {
        dp[i] = min(dp[i+1], (int)s[i]);
    }
    vector<int> a;
    int l = 0;
    string t = "";
    while(l < n) {
        if(a.size() == 0) {
            a.emplace_back(s[l]);
            l++;
        } else if(a.back() <= dp[l]) {
            t += a.back();
            a.pop_back();
        } else {
            a.emplace_back(s[l]);
            l++;
        }
    }
    while(a.size()) {
        t += a.back();
        a.pop_back();
    }
    cout << t << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for (int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}