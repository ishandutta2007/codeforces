#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define pii pair<int, int>
#define ld long double

const int INF = 2e9 + 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        string t = "abacaba";
        for (int i = 0; i < n; i++) {
            string tmp = s;
            for (int j = 0; j < 7 && i + j < n; j++) {
                if (tmp[i + j] == '?') tmp[i + j] = t[j];
            }
            for (auto &c : tmp) {
                if (c == '?') c = 'z';
            }
            int cnt = 0;
            for (int i = 0; i + 7 <= n; i++) {
                cnt += (tmp.substr(i, 7) == t);
            }
            if (cnt == 1) {
                cout << "Yes\n" << tmp << "\n";
                break;
            }
            if (i == n - 1) {
                cout << "No\n";
            }
        }
    }
    return 0;
}