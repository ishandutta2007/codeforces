#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

//vector string deque break continue
#define forn(i, s, f) for (int i = (int)s; i < (int)f; i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pf push_front
#define pb push_back
#define pop_f pop_front
#define pop_b pop_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define x first
#define y second
/*
int n, m;

bool is_valid(pii a) {
    return 0 <= a.x && a.x < n &&
           0 <= a.y && a.y < m;
}

char get(int dir) {
    if (dir == 0)
        return 'R';
    if (dir == 1)
        return 'L';
    if (dir == 2)
        return 'D';
    if (dir == 3)
        return 'U';
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    vector <int> dx = {0, 0, 1, -1},
                 dy = {1, -1, 0, 0};
    int k;
    cin >> n >> m >> k;
    if (k > 4 * n * m - 2 * n - 2 * m)
        return cout << "NO\n", 0;
    vector <pair <pii, int>> st = {{{0, 0}, -1}};
    map <pair <pii, pii>, bool> used;
    forn (steps, 0, k) {
        pii v = st.back().fs;
        int dir = v.sc;
        forn (i, 0, 4) {
            pii u = {v.x + dx[i], v.y + dy[i]};
            if (is_valid(u) && !used[{v, u}]) {
                st.pb({u, i});
                used[{v, u}] = true;
                break;
            }
        }
        if (make_pair(v, dir) == st.back())
            st.pop_back();
        cout << v.fs << " " << v.sc << " " << get(dir);
        cout << "\n";
    }
    return 0;
}*/

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m, k;
    cin >> n >> m >>k;
    if (k > 4 * n * m - 2 * n - 2 * m)
        return cout << "NO\n", 0;
    vector <pair <int, char>> ans;
    forn (i, 0, n - 1) {
        ans.eb(m - 1, 'R');
        ans.eb(m - 1, 'L');
        ans.eb(1, 'D');
    }
    ans.eb(m - 1, 'R');
    forn (i, 0, m - 1) {
        ans.eb(n - 1, 'U');
        ans.eb(n - 1, 'D');
        ans.eb(1, 'L');
    }
    ans.eb(n - 1, 'U');
    vector <pair <int, char>> ANS;
    int done = 0;
    for (auto i : ans) {
        done += i.fs;
        if (done >= k) {
            done -= i.fs;
            if (k - done > 0)
                ANS.eb(k - done, i.sc);
            break;
        }
        //cout << done << ": ";
        if (i.fs)
            ANS.eb(i.fs, i.sc);
    }
    //cout << ans.size() << "\n";
    cout << "YES\n" << ANS.size() << "\n";
    for (auto i : ANS) {
        cout << i.fs  << " " << i.sc << "\n";
    }
    return 0;
}