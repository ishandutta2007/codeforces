#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define vi vector<int>
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second

const int N = 200005;

string s;
int cnt[26][N];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> s;
    s = " " + s;
    int n = s.size() - 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 26; j++) {
            cnt[j][i] = cnt[j][i - 1] + (s[i] - 'a' == j);
        }
    }
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int l, r;
        cin >> l >> r;
        if (s[l] != s[r]) {
            cout << "Yes\n";
            continue;
        }
        int dem = 0;
        for (int j = 0; j < 26; j++) {
            if (cnt[j][r] - cnt[j][l - 1]) dem++;
        }
        if (dem == 1) {
            if (r - l + 1 == 1) {
                cout << "Yes\n";
                continue;
            } else {
                cout << "No\n";
                continue;
            }
        }
        if (dem == 2) {
            cout << "NO\n";
            continue;
        } else {
            cout << "YES\n";
            continue;
        }
    }
    return 0;
}