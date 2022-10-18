#include<bits/stdc++.h>

using namespace std;

int const maxn = 1e6 + 5;
int a[maxn];

main() {
#ifdef karpovich
    freopen("input.txt", "r", stdin);
#endif // karpovich
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map < int, vector < int > > pos;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            pos[a[i]].push_back(i);
        }
        int ans = -1;
        for (auto key : pos) {
            for (int j = 1; j < key.second.size(); ++j) {
                int len = key.second[j - 1] + n - key.second[j];
                if (ans == -1 || len > ans) ans = len;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}