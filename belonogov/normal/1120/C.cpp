#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define sz(a) (int)(a).size()
#define all(a) (a).begin(),a.end()
#define pw(x) (1LL<<(x))

#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n";
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define dbv(a) cerr << #a << " = "; for (auto xxxx: a) cerr << xxxx << " "; cerr << endl

using namespace std;

typedef long long ll;
typedef double dbl;
const int INF = 1.01e9;
const int N = 2e5 + 10;
const int ALF = 26;


bool is_substr(string s, string t) {
    string g = t + s;
    vector<int> z(g.size());
    int l = 0, r = 0;
    for (int i = 1; i < sz(g); i++) {
        if (r > i) {
            z[i] = min(r - i, z[i - l]);
        }
        for (; i + z[i] < sz(g) && g[z[i]] == g[i + z[i]]; z[i]++);
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
        if (i >= sz(t) && z[i] >= sz(t)) {
            return true;
        }
    }
    return false;
}


int main() {
#define TASK "A"
#ifdef HOME
    assert(freopen(TASK".in", "r", stdin));
#endif
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    vector<int> dp(n + 1, INF);
    dp[0] = 0;
    int mx = 0;
    for (int i = 0; i < n; i++) {
        dp[i + 1] = min(dp[i + 1], dp[i] + a);
        for (; i + mx < n && is_substr(s.substr(0, i), s.substr(i, mx + 1)); mx++);
        dp[i + mx] = min(dp[i + mx], dp[i] + b);
        mx = max(mx - 1, 0);
    }

    cout << dp[n] << endl;


}