#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...) 6;
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

int n, m, pref[2005][2005];
char grid[2005][2005];

long long comp(long long rad) {
    return rad * rad + (rad - 1) * (rad - 1);
}

int eval(int r, int c) {
    return r >= 0 && c >= 0 ? pref[r][c] : 0;
}

int query(int r, int c, int rad) {
    return eval(r, c) - eval(r - rad, c - rad) - eval(r - rad, c + rad) + eval(r - 2 * rad, c);
}

bool ok(int r, int c, int rad) {
    if (c - rad + 1 < 0 || c + rad - 1 >= m + 1 || r - 2 * (rad - 1) < 0)
        return false;
//    int color = grid[r][c] - 'a';
//    DEBUG(r, c, color, rad, (c > 0 ? hpref[r][c-1][color] : 0))
//    return hpref[r][c + rad - 1] - hpref[r][c] == rad - 1
//        && (c > 0 ? hpref[r][c-1] - (c >= rad ? hpref[r][c - rad] : 0) : 0) == rad - 1
//        && vpref[r + rad - 1][c] - vpref[r][c] == rad - 1
//        && (r > 0 ? vpref[r-1][c] - (r >= rad ? vpref[r - rad][c] : 0) : 0) == rad - 1;

    DEBUG(r, c, rad, query(r, c, rad), query(r - 1, c, rad - 1))
    return query(r, c, rad) + query(r - 1, c, rad - 1) >= comp(rad);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        string s;
        cin >> s;
        for (int j=1; j<=m; j++)
            grid[i][j] = s[j-1];
    }


    int ret = 0;
    for (int k=0; k<26; k++) {
        // precomp pref sums
        for (int i=0; i<=n+1; i++)
            for (int j=0; j<=m+1; j++)
                pref[i][j] = (1 <= i && i <= n && 1 <= j && j <= m ? (grid[i][j] - 'a' == k) : 0) + eval(i - 1, j - 1) + eval(i - 1, j + 1) - eval(i - 2, j);

        for (int i=1; i<=n; i++)
            for (int j=1; j<=m; j++) {
                // binary search for largest rhombus permitted
                if (grid[i][j] - 'a' != k)
                    continue;
                int l = 1, r = min(n, m) + 1;
                while (l < r) {
                    int mid = (l + r) / 2;
                    if (ok(i, j, mid))
                        l = mid + 1;
                    else
                        r = mid;
                }
                DEBUG(i, j, l - 1)
                ret += l - 1;
            }
    }

    cout << ret << "\n";

    return 0;
}