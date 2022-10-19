#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define vi vector<int>
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second

bool cmp(pair<string, int> x, pair<string, int> y) {
    return x.y < y.y;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n;
        cin >> n;
        string s[n + 1];
        vector<pair<string, int>> v;
        for (int i = 1; i <= n; i++) {
            cin >> s[i];
            v.pb({s[i], i});
        }
        sort(all(v));
        int cnt = 0;
        for (int i = 1; i < n; i++) {
            if (v[i].x == v[i - 1].x) {
                cnt++;
                for (int j = 0; j < 10; j++) {
                    bool flag = 0;
                    for (int k = 0; k < n; k++) {
                        if (k == i - 1) continue;
                        if (v[k].x[0] - '0' == j) flag = 1;
                    }
                    if (flag == 0) {v[i - 1].x[0] = '0' + j; break;}
                }
            }
        }
        sort(all(v), cmp);
        cout << cnt << '\n';
        for (int i = 0; i < n; i++) {
            cout << v[i].x << '\n';
        }
    }
    return 0;
}