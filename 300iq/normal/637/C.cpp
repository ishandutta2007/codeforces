#include <bits/stdc++.h>

using namespace std;

vector <string> gg(1000);
bool good[7];

int main() {
    int n, ans = 6;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> gg[i];
    int lim = (1 << 6);
    for (int i = 0; i < n; i++) {
        for (int t = 0; t <= 6; t++)
            good[t] = 1;
        for (int mask = 0; mask < lim; mask++) {
            string str = gg[i];
            int r = 0;
            for (int f = 0; f < 6; f++)
                if (mask & (1 << f))
                    str[f] = '?';
                else
                    r++;
            bool goood = true;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                int cnt = 0;
                for (int t = 0; t < 6; t++)
                    cnt += (gg[j][t] == str[t] || (str[t] == '?' && gg[i][t] != gg[j][t]));
                goood &= (cnt < r);
            }
            good[6 - r] &= goood;
        }
        int res = 0;
        for (int i = 0; i <= 6; i++) {
            if (good[i])
                res = i;
            else
                break;
        }
        ans = min(ans, res);
    }
    cout << ans << endl;
}