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

const int N = 1e6 + 10;
int n, a[N], b[N], p[N], trace[N];

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    for (int i = 1; i <= n; ++i) p[i] = i + b[i];
    set<int> st;
    for (int i = 0; i < n; ++i) st.insert(i);
    queue<int> q;
    q.push(n);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        int t = u;
        u = p[u];
        while (true)
        {
            auto it = st.lower_bound(u - a[u]);
            if (it == st.end() || *it > u) break;
            int v = *it;
            st.erase(it);
            q.push(v);
            trace[v] = t;
        }
    }
    if (st.count(0))
    {
        cout << -1;
        return 0;
    }
    vi ans;
    int u = 0;
    while (u != n)
    {
        ans.eb(u);
        u = trace[u];
    }
    cout << ans.size() << "\n";
    reverse(all(ans));
    for (int x : ans) cout << x << " ";
    return 0;
}