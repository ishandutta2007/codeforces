#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair<ll, ll> pll;

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7;
const long long gs = 500 * kk;

ll n, m, i, j;
vector<ll> reb[gs + 10];
vector<vector<ll>> v;
vector<ll> col, tc;
bool viv = false;

void DFS(ll v, ll c) {
    c %= 3;
    col[v] = c;
    ll l = reb[v].size();
    for (ll i = 0; i < l; i++) {
        ll s = reb[v][i];
        if (col[s] == -1) {
            DFS(s, c  +1);
        }
    }
}



int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    m = n - 1;
    for (ll j = 0; j < 3; j++) {
        v.push_back({});
        v.back().resize(n);
        for (auto &i : v.back())
            cin >> i;
    }
    for (i = 0; i < m; i++) {
        long a, b;
        cin >> a >> b;
        a--; b--;
        reb[a].push_back(b);
        reb[b].push_back(a);
    }
    col.assign(n, -1);
    tc.assign(n, -1);
    for (ll i = 0; i < n; i++) {
        if (reb[i].size() >= 3) {
            cout << -1 << endl;
            exit(0);
        }
    }
    ll z = -1;
    for (ll i = 0; i < n; i++)
        if (reb[i].size() == 1)
            z = i;
    DFS(z, 0);

    vector<vector<ll>> ans;
    ans.resize(3);
    for (auto &l : ans)
        l.resize(3);
    for (ll i = 0; i < n; i++) {
        ll lev = col[i];
        for (ll j = 0; j < 3; j++)
            ans[j][col[i]] += v[j][i];
    }

    ll res = inf;

    vector<ll> per = {0, 1, 2};
    res = min(ans[0][0] + ans[1][1] + ans[2][2], res);
    auto how = per;
    while(next_permutation(per.begin(), per.end())) {
        ll val = ans[per[0]][0] + ans[per[1]][1]+ ans[per[2]][2];
        res = min(val, res);
        if (res == val)
            how = per;
//        viv = true;
        if (viv) {
            for (auto i : per)
                cout << i << ' ';
            cout << endl;
            cout << val << endl;
        }
    }

    cout << res << endl;
    for (ll i = 0; i < n; i++) {
        cout << how[col[i]] + 1 << ' ';
//        cout << col[how[i]] + 1 << ' ';
    }



    return 0;
}

/**
3
3 2 3
4 3 2
3 1 3
1 3
2 1




**/