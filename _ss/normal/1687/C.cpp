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
vi G[N];

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
        vll a(n + 1, 0);
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 1, x; i <= n; ++i) cin >> x, a[i] = a[i] - x + a[i - 1];
        for (int i = 0; i <= n; ++i) G[i].clear();
        for (int i = 1, l, r; i <= m; ++i)
        {
            cin >> l >> r;
            l--;
            G[l].eb(r);
            G[r].eb(l);
        }
        queue<int> q;
        set<int> st;
        for (int i = 1; i <= n; ++i)
            if (a[i] == 0) q.push(i);
            else st.insert(i);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int v : G[u])
                if (a[v] == 0)
                {
                    if (v > u)
                    {
                        while (true)
                        {
                            auto it = st.lower_bound(u);
                            if (it == st.end() || *it > v) break;
                            int x = *it;
                            a[x] = 0;
                            st.erase(x);
                            q.push(x);
                        }
                    }
                    else
                    {
                        while (true)
                        {
                            auto it = st.lower_bound(v);
                            if (it == st.end() || *it > u) break;
                            int x = *it;
                            a[x] = 0;
                            st.erase(x);
                            q.push(x);
                        }
                    }
                }
        }
        bool check = true;
        for (int i = 0; i <= n; ++i)
            if (a[i] != 0) check = false;
        if (check) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}