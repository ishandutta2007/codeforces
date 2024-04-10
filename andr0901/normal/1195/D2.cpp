#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
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

int nxt() {
    int x;
    cin >> x;
    return x;
}

const int MOD = 998244353;

int add(int x, int y) {
    x += y;
    if (x >= MOD)
        return x - MOD;
    return x;
}

int sub(int x, int y) {
    x -= y;
    if (x < 0)
        return x + MOD;
    return x;
}

int mul(int x, int y) {
    return (1LL * x * y) % MOD;
}

int main() {
    //ios_base::sync_with_stdio(0), cin.tie(0);
    vector <int> p(20, 1);
    forn (i, 1, 20)
        p[i] = mul(p[i - 1], 10);
    int n = nxt();
    vector <vector <int>> a(n);
    vector <int> cnt(11);
    forn (i, 0, n) {
        int t = nxt();
        vector <int> b;
        while (t) {
            b.pb(t % 10);
            t /= 10;
        }   
        reverse(all(b));
        a[i] = b;
        cnt[sz(b)]++;
    }
    vector <vector <vector <int>>> c(11, vector <vector <int>> (11)), d(11, vector <vector <int>> (11));
    forn (i, 1, 11) {
        forn (j, 1, 11) {
            int idx = i + j - 1, _i = i, _j = j;
            while (_i >= _j) {
                c[i][j].pb(idx);
                _i--;
                idx--;
            }
            while (_i < _j) {
                d[i][j].pb(idx);
                _j--;
                idx--;
            }
            bool flag = 1;
            while (idx > -1) {
                if (flag) {
                    c[i][j].pb(idx);
                    _i--;
                } else {
                    d[i][j].pb(idx);
                    _j--;
                }
                idx--;
                flag = (!flag);
            }
            /*cout << i << " " << j << ":\n";
            forn (k, 0, sz(c[i][j]))
                cout << c[i][j][k] << " ";
            cout << "\n";
            forn (k, 0, sz(d[i][j]))
                cout << d[i][j][k] << " ";
            cout << "\n\n";*/
        }
    }
    int ans = 0;
    forn (i, 0, n) {
        forn (j, 1, 11) {
            if (!cnt[j])
                continue;
            int to_add = 0;
            forn (k, 0, sz(a[i])) {
                //cout << a[i][k] << " " << c[sz(a[i])][j][k] << "\n";
                to_add = add(to_add, mul(a[i][k], add(p[c[sz(a[i])][j][k]], p[d[j][sz(a[i])][k]])));
            }
            //cout << to_add << " " << i << " " << j << " " << cnt[j] << "\n";
            ans = add(ans, mul(to_add, cnt[j]));
        }
        //ans = sub(ans, to_add)
    }
    cout << ans;
    return 0;
}