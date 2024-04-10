#include <bits/stdc++.h>

using namespace std;

int pref_R[200005][3];
int pref_G[200005][3];
int pref_B[200005][3];

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q, n, k;
    cin >> q;
    string s;
    for (int i = 1; i <= q; ++i) {
        cin >> n >> k;
        cin >> s;
        //cout << "OK" << endl;
        for (int j = 1; j <= n; ++j) {
            for (int z = 0; z <= 2; ++z) {
                pref_R[j][z] = 0, pref_B[j][z] = 0, pref_G[j][z] = 0;
            }
        }
        //cout << "OK" << endl;
        for (int j = 1; j <= n; ++j) {
            for (int z = 0; z <= 2; ++z) {
                pref_R[j][z] = pref_R[j - 1][z];
                pref_G[j][z] = pref_G[j - 1][z];
                pref_B[j][z] = pref_B[j - 1][z];
                if (j % 3 == z) {
                    if (s[j - 1] == 'R') pref_G[j][z]++, pref_B[j][z]++;
                    else if (s[j - 1] == 'B') pref_G[j][z]++, pref_R[j][z]++;
                    else pref_R[j][z]++, pref_B[j][z]++;
                }
            }
        }
        //cout << "OK" << endl;
        int ans = 1e9;
        for (int j = 1; j + k - 1 <= n; ++j) {
            ans = min(ans, pref_R[j + k - 1][0] - pref_R[j - 1][0] + pref_G[j + k - 1][1] - pref_G[j - 1][1] + pref_B[j + k - 1][2] - pref_B[j - 1][2]);
            ans = min(ans, pref_R[j + k - 1][1] - pref_R[j - 1][1] + pref_G[j + k - 1][2] - pref_G[j - 1][2] + pref_B[j + k - 1][0] - pref_B[j - 1][0]);
            ans = min(ans, pref_R[j + k - 1][2] - pref_R[j - 1][2] + pref_G[j + k - 1][0] - pref_G[j - 1][0] + pref_B[j + k - 1][1] - pref_B[j - 1][1]);
        }
        cout << ans << '\n';
    }
    return 0;
}