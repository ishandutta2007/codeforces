#include<bits/stdc++.h>

using namespace std;

int const maxn = 3e6 + 5;
vector < int > a[maxn];

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k, cur = 0, sum = 0;
    cin >> n >> k;
    string s;
    cin >> s;
    while (1) {
        int oks = 1, d = 0;
        for (auto c : s) {
            if (c == 'L' && d) oks = 0;
            if (c == 'R') d = 1;
        }
        if (oks) break;
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == 'R' && s[i + 1] == 'L') {
                sum++;
                swap(s[i], s[i + 1]);
                a[cur].push_back(i + 1);
                ++i;
            }
        }
        cur++;
    }
    if (sum < k || k < cur) {
        cout << -1 << '\n';
        exit(0);
    }
    for (int i = 0; i < cur; ++i) {
        for (int j = 0; j < (int)a[i].size(); ++j) {
            if (1 + cur - i - 1 == k) {
                cout << (int)a[i].size() - j << " ";
                for (int pos = j; pos < (int)a[i].size(); ++pos) cout << a[i][pos] << " ";
                cout << '\n';
                k--;
                break;
            }
            cout << 1 << " " << a[i][j] << '\n';
            k--;
        }
    }
    return 0;
}