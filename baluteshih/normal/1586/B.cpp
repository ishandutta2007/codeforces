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

int tag[100005];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        fill(tag + 1, tag + n + 1, 0);
        for (int i = 1; i <= m; ++i) {
            int a, b, c;
            cin >> a >> b >> c;
            tag[b] = 1;
        }
        for (int i = 1; i <= n; ++i) {
            if (tag[i]) continue;
            for (int j = 1; j <= n; ++j)
                if (i != j)
                    cout << i << " " << j << "\n";
            break;
        }
    }
}