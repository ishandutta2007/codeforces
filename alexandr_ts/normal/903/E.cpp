#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 2e9 + 10;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;
const int N = 1e4 + 10;

string s[N];

bool ok(string t, int n, int m) {
    for (int i = 0; i < n; i++) {
        vector <int> tmp;
        for (int j = 0; j < m; j++)
            if (t[j] != s[i][j])
                tmp.pb(j);
        if (tmp.size() != 0 && tmp.size() != 2) return false;
        if (tmp.size() == 2) {
            int l = tmp[0], r = tmp[1];
            if (!(t[l] == s[i][r] && t[r] == s[i][l])) return false;
        }
        if (tmp.size() == 0) {
            vector <int> cnt(26, 0);
            for (int i = 0; i < t.size(); i++)
                cnt[t[i] - 'a']++;
            if (*max_element(cnt.begin(), cnt.end()) < 2) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    //freopen("a.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> s[i];

    for (int i = 0; i < n; i++)
        if (ok(s[i], n, m)) {
            cout << s[i];
            return 0;
        }

    int i1 = -1, i2 = -1, pos = -1;
    for (int i = 0; i < n && i1 == -1; i++)
        for (int j = i + 1; j < n && i1 == -1; j++)
            for (int k = 0; k < m && i1 == -1; k++)
                if (s[i][k] != s[j][k])
                    i1 = i, i2 = j, pos = k;
    if (i1 == -1) {
        swap(s[0][0], s[0][1]);
        cout << s[0];
        return 0;
    }
    string tmp = s[i1];
    for (int i = 0; i < m; i++) {
        swap(tmp[i], tmp[pos]);
        if (ok(tmp, n, m)) {
            cout << tmp;
            return 0;
        }
        swap(tmp[i], tmp[pos]);
    }


    tmp = s[i2];
    for (int i = 0; i < m; i++) {
        swap(tmp[i], tmp[pos]);
        if (ok(tmp, n, m)) {
            cout << tmp;
            return 0;
        }
        swap(tmp[i], tmp[pos]);
    }

    cout << -1;

}