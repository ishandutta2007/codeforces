#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<vector<ll> > mat;

const ld PI = acos(-1);
const ll INF = 1e15 + 10;
const int LOG = 20;
const ll MOD = 1e9 + 7;
const int N = 1e6 + 10;

ll a[N];
ll b[N];

void gen(int n, int k) {
    for (int mask = 0; mask < (1 << n); mask++) {
//        if (mask & 1) continue;
        string s;
        for (int i = 0; i < n; i++)
            if (mask & (1 << i))
                s += "1";
            else
                s += "0";
        map<string, int> mp;
        for (int l = 0; l < n; l++)
            for (int r = l; r < n; r++) {
                string tmp = s.substr(l, r - l + 1);
                mp[tmp]++;
            }
        int minlen = n + 1;
        for (auto x: mp)
            if (x.second == 1)
                minlen = min(minlen, (int)x.first.size());
        if (minlen == k) {
            cout << s << endl;
        }
    }

}

bool check(string& s, int n, int k) {
    map<string, int> mp;
    for (int l = 0; l < n; l++)
        for (int r = l; r < n; r++) {
            string tmp = s.substr(l, r - l + 1);
            mp[tmp]++;
        }
    int minlen = n + 1;
    for (auto x: mp)
        if (x.second == 1)
            minlen = min(minlen, (int)x.first.size());
    return minlen == k;
}

void solve() {
//    int n, k;
//    while (cin >> n >> k) {
//        gen(n, k);
//    }
    int n, k;
    cin >> n >> k;
    string ans;
    if (k == 1) {
        ans += "0";
        fr(i, n - 1)
            ans += "1";
    } else {
        int len = (n - k) / 2 + 1;
        for (int i = 0; i < n; i++)
            if (i % len == 0)
                ans += "1";
            else
                ans += "0";
    }
    cout << ans;
    //cout << check(ans, n, k) << " " << n << " " << k << " " << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("a.in", "r", stdin);
    solve();

}