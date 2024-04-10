#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define int ll
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0); cin.sync_with_stdio(0)

const int MN = 2005;

int a[MN][MN], n, freq[MN], ans[MN];
char c;

int32_t main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> c;
                a[i][j] = c - '0';
                freq[a[i][j]]++;
            }
        }
        for (int d = 0; d < 10; d++) {
            if (freq[d] <= 1) continue;
            int tmp = 0;
            vector<int> v[MN];
            int lo = 0x3f3f3f3f, hi = 0;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (a[i][j] == d) v[i].push_back(j), lo = min(lo, i), hi = i;
                }
            }
            for (int i = 1; i <= n; i++) {
                if (v[i].size() <= 0) continue;
                tmp = max(tmp, (v[i].back() - v[i].front()) * (abs(i - lo)));
                tmp = max(tmp, (v[i].back() - v[i].front()) * (abs(hi - i)));
                tmp = max(tmp, (n - v[i].front()) * (abs(i - lo)));
                tmp = max(tmp, (n - v[i].front()) * (abs(hi - i)));
                tmp = max(tmp, (v[i].back() - 1) * (abs(i - lo)));
                tmp = max(tmp, (v[i].back() - 1) * (abs(hi - i)));
                tmp = max(tmp, (v[i].back() - v[i].front()) * (abs(i - 1)));
                tmp = max(tmp, (v[i].back() - v[i].front()) * (abs(n - i)));
            }
            ans[d] = max(ans[d], tmp);
        }
        for (int d = 0; d < 10; d++) {
            if (freq[d] <= 1) continue;
            int tmp = 0;
            vector<int> v[MN];
            int lo = 0x3f3f3f3f, hi = 0;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (a[j][i] == d) v[i].push_back(j), lo = min(lo, i), hi = i;
                }
            }
            for (int i = 1; i <= n; i++) {
                if (v[i].size() <= 0) continue;
                tmp = max(tmp, (v[i].back() - v[i].front()) * (abs(i - lo)));
                tmp = max(tmp, (v[i].back() - v[i].front()) * (abs(hi - i)));
                tmp = max(tmp, (n - v[i].front()) * (abs(i - lo)));
                tmp = max(tmp, (n - v[i].front()) * (abs(hi - i)));
                tmp = max(tmp, (v[i].back() - 1) * (abs(i - lo)));
                tmp = max(tmp, (v[i].back() - 1) * (abs(hi - i)));
                tmp = max(tmp, (v[i].back() - v[i].front()) * (abs(i - 1)));
                tmp = max(tmp, (v[i].back() - v[i].front()) * (abs(n - i)));
            }
            ans[d] = max(ans[d], tmp);
        }
        for (int i = 0; i < 10; i++) printf("%d ", ans[i]);
        printf("\n");
        for (int i = 0; i < 10; i++) freq[i] = ans[i] = 0;
    }

    return 0;
 }