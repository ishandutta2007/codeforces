#include <bits/stdc++.h>
 
using namespace std;
 
#define pb emplace_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define pii pair<int, int>
#define puu pair<unsigned, unsigned>
#define ll long long
#define mp make_pair
#define ui unsigned
#define ull unsigned long long
#define ld double
#define pld pair<ld, ld>
#define pll pair<ll, ll>
 
const int INF = 1e9 + 1;
const ll INFLL = 1e18;

int main() {
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    #endif
    int n, a, b, k;
    cin >> n >> a >> b >> k;
    string s;
    cin >> s;
    int now = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            continue;
        }
        int j = i;
        while (j + 1 < n && s[j + 1] == '0') {
            j++;
        }
        now += (j - i + 1) / b;
        i = j;
    }
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            continue;
        }
        int j = i;
        while (j + 1 < n && s[j + 1] == '0') {
            j++;
        }
        for (int k = i + (b - 1); k <= j && now >= a; k += b) {
            ans.pb(k);
            now--;
        }
        i = j;
    }
    cout << ans.size() << "\n";
    for (auto &c : ans) cout << c + 1 << " ";
    return 0;
}