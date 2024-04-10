#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int q;
    cin >> q;
    while(q--) {
        vector<int> occ(3, 0);
        {
            int n;
            cin >> n;
            while(n--) {
                int x;
                cin >> x;
                ++occ[x%3];
            }
        }
        int ans = occ[0];
        {
            int m = min(occ[1], occ[2]);
            occ[1] -= m;
            occ[2] -= m;
            ans += m;
        }
        ans += occ[1] / 3;
        ans += occ[2] / 3;
        cout << ans << '\n';
    }
    return 0;
}