#include<bits/stdc++.h>

using namespace std;

int const maxn = 1e6 + 5;
int lr[maxn], du[maxn];
int minlr[maxn], maxlr[maxn], mindu[maxn], maxdu[maxn];

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        for (int i = 0; i < (int)s.size(); ++i) {
            lr[i + 1] = lr[i];
            du[i + 1] = du[i];
            if (s[i] == 'L') lr[i + 1]--;
            else if (s[i] == 'R') lr[i + 1]++;
            else if (s[i] == 'U') du[i + 1]--;
            else du[i + 1]++;
            minlr[i + 1] = min(minlr[i], lr[i + 1]);
            maxlr[i + 1] = max(maxlr[i], lr[i + 1]);
            mindu[i + 1] = min(mindu[i], du[i + 1]);
            maxdu[i + 1] = max(maxdu[i], du[i + 1]);
        }
        for (int cnt = (int)s.size(); cnt >= 0; --cnt) {
            if (-minlr[cnt] + maxlr[cnt] < m && -mindu[cnt] + maxdu[cnt] < n) {
                cout << -mindu[cnt] + 1 << " " << -minlr[cnt] + 1 << '\n';
                break;
            }
        }
    }
    return 0;
}