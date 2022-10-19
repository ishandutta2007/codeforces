#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        vector<int> cur(s.size() + 1);
        vector<int> ind(s.size() * 2 + 1, -1);
        int m = s.size();
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '+')
                cur[i + 1] = cur[i] + 1;
            else
                cur[i + 1] = cur[i] - 1;
            if(ind[cur[i+1]+s.size()] == -1)
                ind[cur[i + 1] + s.size()] = i;
            m = min(m, cur[i + 1]);
        }
        for (int i = 1; i < ind.size(); ++i) {
            if (ind[i - 1] != -1) {
                if (ind[i] == -1)
                    ind[i] = ind[i - 1];
                else
                    ind[i] = min(ind[i], ind[i - 1]);
            }
        }
        int res = 0;
        for (int init = 0; init <= s.size(); ++init) {
            if (init == s.size()) {
                res += s.size();
                break;
            }
            if (ind[-init - 1 + s.size()] == -1) {
                res += s.size();
                break;
            }
            res += ind[-init - 1 + s.size()] + 1;
        }
        cout << res << "\n";
    }
    return 0;
}