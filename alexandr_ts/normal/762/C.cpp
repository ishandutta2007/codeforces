#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
#define s second
#define f first

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5 + 10;
const ll INF = 2e5 + 1;
const int MOD = 1e9 + 7;
const ld EPS = 1e-9;

int a[N], b[N];

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();

    int cur = 0;
    for (int i = 0; i < m; i++) {
        if (i && a[i] == INF) {
            a[i + 1] = INF;
            continue;
        }
        while (cur < n && s[cur] != t[i])
            cur++;
        if (cur < n && s[cur] == t[i])
            a[i + 1] = cur++;
        else
            a[i + 1] = INF;
    }

    cur = n - 1;
    for (int i = m - 1; i >= 0; i--) {
        if (i < m - 1 && b[i + 1] == -INF) {
            b[i] = -INF;
            continue;
        }
        while (cur >= 0 && s[cur] != t[i])
            cur--;
        if (cur >= 0 && s[cur] == t[i])
            b[i] = cur--;
        else
            b[i] = -INF;
    }
//    fr(i, m)
//        cout << a[i] << " ";cout << endl;
//    fr(i, m)
//        cout << b[i] << " ";cout << endl;
    int l, r, ans = m;
    cur = 0;
    a[0] = -INF + 1;
    b[m] = INF - 1;

//    for (int i = 0; i < m; i++) { ///works
//        for (int j = i; j < m; j++) {
//            int lft = a[i];
//            int rgt = b[j + 1];
//            if (lft < rgt && ans > j - i + 1)
//                ans = j - i + 1, l = i, r = j;
//        }
//    }

    for (int i = 0; i <= m; i++) {
        cur = max(cur, i);
        while (cur <= m && b[cur] <= a[i])
            cur++;
        if (cur <= m && b[cur] > a[i])
            if (ans > cur - i)
                ans = cur - i, l = i, r = cur - 1;
    }

    if (ans == m) {
        cout << "-";
        return 0;
    }
    //cout << l << " " << r << " " << ans << endl;
    cout << t.substr(0, l) + t.substr(r + 1, (int)t.size() - r - 1);
}