#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define pii pair<int, int>
#define ld long double
#define mp make_pair
#define ull unsigned long long

const int INF = 1e9 + 1;
const ll INFLL = (ll)1e18 + 1;

vector<int> di = {-1, -1, -1, 0, 1, 1, 1, 0};
vector<int> dj = {-1, 0, 1, 1, 1, 0, -1, -1};

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int h, w;
        cin >> h >> w;
        vector<vector<int>> a(h, vector<int>(w));
        for (int j = 0; j < w; j++) {
            int i = 0;
            bool ok = 1;
            for (int k = 0; k < 8; k++) {
                int ni = i + di[k], nj = j + dj[k];
                if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
                if (a[ni][nj] == 1) ok = 0;
            }
            a[i][j] = ok;
        }
        for (int i = 1; i < h; i++) {
            int j = w - 1;
            bool ok = 1;
            for (int k = 0; k < 8; k++) {
                int ni = i + di[k], nj = j + dj[k];
                if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
                if (a[ni][nj] == 1) ok = 0;
            }
            a[i][j] = ok;
        }
        for (int j = w - 2; j >= 0; j--) {
            int i = h - 1;
            bool ok = 1;
            for (int k = 0; k < 8; k++) {
                int ni = i + di[k], nj = j + dj[k];
                if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
                if (a[ni][nj] == 1) ok = 0;
            }
            a[i][j] = ok;
        }
        for (int i = h - 2; i >= 0; i--) {
            int j = 0;
            bool ok = 1;
            for (int k = 0; k < 8; k++) {
                int ni = i + di[k], nj = j + dj[k];
                if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
                if (a[ni][nj] == 1) ok = 0;
            }
            a[i][j] = ok;
        }
        for (auto &c : a) {
            for (auto &l : c) cout << l;
            cout << "\n";
        }
        cout << "\n";
    }
    return 0;
}