#include <bits/stdc++.h>

using namespace std;

#define M 1010
#define mp make_pair

int n, m;
string s[M];
int p[M], h[M];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> s[i];

    int ans = 0;
    fill(p, p + n, 0);
    for (int i = 0; i < m; ++i) {
        bool flag = true;
        for (int j = 0; j + 1 < n; ++j)
            if (mp(p[j], s[j][i]) > mp(p[j + 1], s[j + 1][i])) {
                ++ans;
                flag = false;
                break;
            }

        if (!flag)
            continue;

        int k = 0;
        for (int j = 1; j < n; ++j) {
            if (mp(p[j], s[j][i]) > mp(p[j - 1], s[j - 1][i])) {
                ++k;
            }
            h[j] = k;
        }

        for (int j = 0; j < n; ++j)
            p[j] = h[j];

    }

    cout << ans << "\n";

    return 0;
}