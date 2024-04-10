#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2100);
const int N = 100005;
const pair<int, int> M = m_p(1000000007, 1000000009);
const int P = 303, S = 55;
const int Q = S * N;
 
pair<int, int> sum(const pair<int, int>& a, const pair<int, int>& b)
{
    return m_p((a.fi + b.fi) % M.fi, (a.se + b.se) % M.se);
}
 
pair<int, int> pro(const pair<int, int>& a, const pair<int, int>& b)
{
    return m_p((a.fi * 1LL * b.fi) % M.fi, (a.se * 1LL * b.se) % M.se);
}
 
pair<int, int> dif(const pair<int, int>& a, const pair<int, int>& b)
{
    return m_p((a.fi - b.fi + M.fi) % M.fi, (a.se - b.se + M.se) % M.se);
}
 
int n;
string s;
int q;
 
int z;
map<int, int> t[Q];
vector<int> v[Q];
 
int zz[N + N];
char aa[N + N];
 
void solv()
{
    cin >> s;
    n = s.size();
    string ss = '0' + s;
    s = ss;
 
    for (int i = 1; i <= n; ++i)
    {
        int pos = 0;
        for (int j = i; j <= n && j - i + 1 < S; ++j)
        {
            if (!t[pos][s[j] - 'a'])
                t[pos][s[j] - 'a'] = ++z;
            pos = t[pos][s[j] - 'a'];
            v[pos].push_back(i);
        }
    }
 
    cin >> q;
    while (q--)
    {
        string u;
        int k;
        cin >> k >> u;
        int m = u.size();
        if (m < S)
        {
            int pos = 0;
            bool f = true;
            for (int j = 0; j < m; ++j)
            {
                if (!t[pos][u[j] - 'a'])
                {
                    f = false;
                    break;
                }
                pos = t[pos][u[j] - 'a'];
            }
            if (!f)
            {
                cout << "-1\n";
                continue;
            }
            if (sz(v[pos]) < k)
            {
                cout << "-1\n";
                continue;
            }
            int ans = n;
            for (int j = 0; j < sz(v[pos]) - k + 1; ++j)
            {
                ans = min(ans, v[pos][j + k - 1] - v[pos][j] + m);
            }
            cout << ans << "\n";
            continue;
        }
        int nn = 0;
        for (int i = 0; i < m; ++i)
            aa[nn++] = u[i];
        for (int i = 1; i <= n; ++i)
            aa[nn++] = s[i];
        aa[nn] = 0;
        int j = 0, r = 0;
        for (int i = 1; i < nn; ++i)
        {
            zz[i] = 0;
            if (i <= r)
                zz[i] = min(r - i + 1, zz[i - j]);
            while (aa[i + zz[i]] == aa[zz[i]])
                ++zz[i];
            if (i + zz[i] - 1 > r)
            {
                r = i + zz[i] - 1;
                j = i;
            }
        }
        vector<int> vv;
        for (int i = m; i < nn; ++i)
        {
            if (zz[i] >= m)
                vv.push_back(i);
        }
        if (sz(vv) < k)
        {
            cout << "-1\n";
            continue;
        }
        int ans = n;
        for (int j = 0; j < sz(vv) - k + 1; ++j)
        {
            ans = min(ans, vv[j + k - 1] - vv[j] + m);
        }
        cout << ans << "\n";
    }
}
 
int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);
    solv();
    return 0;
}
 
//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}