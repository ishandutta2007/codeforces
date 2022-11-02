#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double
#define all(x) x.begin(), x.end()

const int maxn = 5009;
vector<pii> p[2 * maxn];
vector<int> g[2 * maxn];
vector<int> primes;
int mn[maxn];
int cnt[2 * maxn];
int n, N;
int sz[2 * maxn];

int check(vector<pii>& p1, vector<pii>& p2)
{
    int sum1 = 0;
    for (pii e : p1)
        sum1 += e.ss;
    int sum2 = 0;
    for (pii e : p2)
        sum2 += e.ss;
    if (sum1 < sum2)
        return 1;
    if (sum1 == sum2)
        return 2;
    return 0;
}

void print(vector<pii>& p1)
{
    for (pii e : p1)
        cout << e.ff << " " << e.ss << "  ";
    cout << "\n";
}

void find_lca(vector<pii>& p1, vector<pii>& p2, int i, vector<pii>& p3, vector<int>& st)
{
    p3.resize(0);
    int j = 0;
    while (j < (int)p1.size() && j < (int)p2.size() &&
           p1[(int)p1.size() - 1 - j] == p2[(int)p2.size() - 1 - j])
            j++;
    if (j < (int)p1.size() && p1[(int)p1.size() - 1 - j].ff == p2[(int)p2.size() - 1 - j].ff)
        p3.pb(p1[(int)p1.size() - 1 - j]);
    j--;
    while (j >= 0)
    {
        p3.pb(p1[(int)p1.size() - 1 - j]);
        j--;
    }
//    print(p1);
//    print(p2);
//    print(p3);
    int pr = -1;
    while (!st.empty() && check(p[st.back()], p3) == 0)
    {
        if (pr != -1)
        {
            g[pr].pb(st.back());
            g[st.back()].pb(pr);
        }
        pr = st.back();
        st.pop_back();
    }
//    for (int v = 1; v < n; v++)
//    {
//        cout << v << ":\n";
//        for (int to : g[v])
//            cout << " " << to;
//        cout << "\n";
//    }
//    cout << "\n";
    if (!st.empty() && check(p3, p[st.back()]) == 2)
    {
        p3.resize(0);
        if (pr != -1)
        {
            g[pr].pb(st.back());
            g[st.back()].pb(pr);
        }
    }
    else
    {
        st.pb(n);
        g[n].resize(0);
        if (pr != -1)
        {
            g[pr].pb(st.back());
            g[st.back()].pb(pr);
        }
        n++;
    }
    if (check(p3, p2) == 1)
        st.pb(i);
//    for (int e : st)
//        cout << " ! " << e;
//    cout << "\n";
//    for (int v = 1; v < n; v++)
//    {
//        cout << v << ":\n";
//        for (int to : g[v])
//            cout << " " << to;
//        cout << "\n";
//    }
//    cout << "\n\n\n";
}

int check_graph()
{
    map<int, int> m;
    for (int i = 1; i < n; i++)
    {
        int u = 1;
        for (pii e : p[i])
        {
            for (int j = 0; j < e.ss; j++)
                u *= e.ff;
        }
        if (m.find(u) != m.end())
        {
            cout << i << " " << u << " " << m[u] << endl;
            return 1;
        }
        m[u] = i;
    }
    for (int i = 2; i < n; i++)
    {
        int u = 1;
        for (pii e : p[i])
        {
            for (int j = 0; j < e.ss; j++)
                u *= e.ff;
        }
        int cnt = 0;
        for (int to : g[i])
        {
            int y = 1;
            for (pii e : p[to])
            {
                for (int j = 0; j < e.ss; j++)
                    y *= e.ff;
            }
            if (u % y == 0)
                cnt++;
            else if (y % u != 0)
            {
                cout << i << " " << to << " " << u << " " << y << endl;
                return 2;
            }
        }
        if (cnt > 1)
            return 3;
        cout << i << " " << u << endl;
        while (u > 1)
        {
//            cout << "   " << mn[u] << endl;
            u /= mn[u];
            cout << " " << u << endl;
            if (m.find(u) != m.end())
            {
                int v = m[u];
                bool fl = 0;
                for (int to : g[i])
                {
                    if (to == v)
                        fl = 1;
                }
                if (!fl)
                {

                    return 4;
                }
                break;
            }
        }
//        cout << i << endl;
    }
    for (int i = 1; i < n; i++)
    {
        for (int k = i + 1; k < n; k++)
        {
            int u = 1;
            for (pii e : p[i])
            {
                for (int j = 0; j < e.ss; j++)
                    u *= e.ff;
            }
            int y = 1;
            for (pii e : p[k])
            {
                for (int j = 0; j < e.ss; j++)
                    y *= e.ff;
            }
            while (u != y)
            {
                if (u > y)
                    u /= mn[u];
                else
                    y /= mn[y];
            }
            if (m.find(u) == m.end())
                return 5;
        }
    }
    return 0;
}

void find_sz(int v, int pr)
{
    sz[v] = cnt[v];
    for (int to : g[v])
    {
        if (to == pr)
            continue;
        find_sz(to, v);
        sz[v] += sz[to];
    }
}

int find_c(int v, int pr)
{
    for (int to : g[v])
    {
        if (to == pr)
            continue;
        if (sz[to] >= (N + 1) / 2)
            return find_c(to, v);
    }
    return v;
}

int find_ans(int v, int pr)
{
    int ans = 0;
    for (int to : g[v])
    {
        if (to == pr)
            continue;
        int kek = 0;
        for (pii e : p[to])
            kek += e.ss;
        for (pii e : p[v])
            kek -= e.ss;
        kek = abs(kek);
        ans += find_ans(to, v) + sz[to] * kek;
    }
    return ans;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // LOCAL
    for (int i = 2; i < maxn; i++)
        mn[i] = i;
    for (int i = 2; i < maxn; i++)
    {
        if (mn[i] == i)
            primes.pb(i);
        int u = i;
        int e = 0;
        while (u > 1)
        {
            while (e < (int)p[i - 1].size() && p[i - 1][e].ff <= mn[u])
            {
                p[i].pb(p[i - 1][e]);
                e++;
            }
            if (!p[i].empty() && p[i].back().ff == mn[u])
                p[i].back().ss++;
            else
                p[i].pb(mn[u], 1);
            u /= mn[u];
        }
        while (e < (int)p[i - 1].size())
        {
            p[i].pb(p[i - 1][e]);
            e++;
        }
        for (int e : primes)
        {
            if (e > mn[i] || e * i >= maxn)
                break;
            mn[e * i] = e;
        }
    }
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        if (!x)
            x = 1;
        cnt[x]++;
    }
    n = maxn;
    vector<int> st;
    st.pb(1);
    st.pb(2);
    for (int i = 3; i < maxn; i++)
        find_lca(p[i - 1], p[i], i, p[n], st);
    int pr = -1;
    while (!st.empty())
    {
        if (pr != -1)
        {
            g[st.back()].pb(pr);
            g[pr].pb(st.back());
        }
        pr = st.back();
        st.pop_back();
    }
    //cout << check_graph();
//    for (int i = 1; i < n; i++)
//    {
//        int u = 1;
//        for (pii e: p[i])
//        {
//            for (int j = 0; j < e.ss; j++)
//                u *= e.ff;
//        }
//        cout << i << " " << u << ":\n ";
//        for (int e : g[i])
//            cout << e << " ";
//        cout << "\n";
//    }
    find_sz(1, -1);
    int v = find_c(1, -1);
    find_sz(v, -1);
    cout << find_ans(v, -1);
}