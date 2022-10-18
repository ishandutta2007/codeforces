#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

vector<int> G[200005];
set<int> readd;
int in[200005];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, ans = 0, cnt = 0;
        cin >> n;
        for (int i = 1; i <= n; ++i)
            G[i].clear();
        readd.clear();
        for (int i = 1; i <= n; ++i) {
            cin >> in[i];
            for (int j = 1; j <= in[i]; ++j) {
                int x;
                cin >> x;
                G[x].pb(i);
            }
            if (in[i] == 0)
                readd.insert(i);
        }
        while (cnt < n) {
            if (readd.empty()) break;
            ++ans;
            auto p = readd.begin();
            while (p != readd.end()) {
                int nw = *p;
                ++cnt;
                for (int j : G[nw])
                    if (!--in[j])
                        readd.insert(j);
                readd.erase(nw);
                p = readd.lower_bound(nw);
            }
        }
        if (cnt < n)
            cout << "-1\n";
        else
            cout << ans << "\n";
    }
}