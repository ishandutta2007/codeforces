#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(), vr.end()

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;

const int N = 2e5 + 10;
vi vt[N];

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        bool check = true;
        set<pii> st;
        set<int> un_changed;
        for (int i = 1; i <= n; ++i)
        {
            vt[i].clear();
            for (int j = 1, x; j <= m; ++j) cin >> x, vt[i].eb(x);
            vi s = vt[i];
            sort(all(s));
            set<int> dif;
            for (int j = 0; j < m; ++j)
                if (s[j] != vt[i][j]) dif.insert(j + 1);
            if ((int)dif.size() > 2) check = false;
            else if ((int)dif.size() == 2) st.insert(mp(*dif.begin(), *next(dif.begin())));
            else un_changed.insert(i);
        }
        if ((int)st.size() > 1) check = false;
        pii pa = mp(1, 1);
        if (!st.empty())
        {
            pa = *st.begin();
            for (int id : un_changed)
                if (vt[id][pa.fi - 1] != vt[id][pa.se - 1]) check = false;
        }
        if (!check) cout << "-1\n";
        else cout << pa.fi << " " << pa.se << "\n";
    }
    return 0;
}