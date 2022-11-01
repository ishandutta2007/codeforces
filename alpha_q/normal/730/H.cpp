#include <bits/stdc++.h>

using namespace std;

const int N = 110;

bool mark[N];
string s[N], res;
int n, m, len = -1, flag = 1;

int main (int argc, char const *argv[]) {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> s[i];
    for (int i = 1; i <= m; ++i) {
        int p; cin >> p;
        mark[p] = 1;

        if (flag == 0) continue;

        if (len == -1) {
            len = s[p].size();
            res = s[p];
        } else if ((int) s[p].size() != len) {
            flag = 0;
            continue;
        }

        for (int i = 0; i < len; ++i) {
            if (res[i] != s[p][i]) {
                res[i] = '?';
            }
        }
    }

    if (flag == 0) {
        puts("No");
        return 0;
    }

    for (int i = 1; i <= n; ++i) {
        if (!mark[i] and (int) s[i].size() == len) {
            int match = 1;
            for (int j = 0; j < len; ++j) {
                if (res[j] != '?' and res[j] != s[i][j]) {
                    match = 0;
                    break;
                }
            }
            if (match) {
                flag = 0;
                break;
            }
        }
    }

    if (flag == 0) puts("No");
    else {
        puts("Yes");
        cout << res << '\n';
    }
    return 0;
}