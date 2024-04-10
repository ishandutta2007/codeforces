#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 300005, m = 20;
 
int n;
int d[N];
int p[N][m];
int q[N];
 
int dist(int x, int y)
{
    if (d[x] < d[y])
        swap(x, y);
 
    int ans = 0;
    for (int i = m - 1; i >= 0; --i)
    {
        if (p[x][i] && d[p[x][i]] >= d[y])
        {
            ans += (1 << i);
            x = p[x][i];
        }
    }
 
    assert(d[x] == d[y]);
 
    for (int i = m - 1; i >= 0; --i)
    {
        if (p[x][i] != p[y][i])
        {
            ans += (1 << i) * 2;
            x = p[x][i];
            y = p[y][i];
        }
    }
 
    if (x != y)
        ans += 2;
 
    return ans;
}
 
void solv()
{
    cin >> n;
    ++n;
 
    set<int> s1, s2;
    s1.insert(1);
    for (int x = 2; x <= n; ++x)
    {
        cin >> p[x][0];
        d[x] = d[p[x][0]] + 1;
        for (int i = 1; i < m; ++i)
        {
            p[x][i] = p[p[x][i - 1]][i - 1];
        }
 
        if (x == 2)
        {
            s2.insert(2);
        }
        else
        {
            int d = dist(*s1.begin(), *s2.begin());
            int d1 = dist(*s1.begin(), x);
            int d2 = dist(*s2.begin(), x);
 
            if (max(d1, d2) == d)
            {
                if (d1 > d2)
                    s2.insert(x);
                else
                    s1.insert(x);
            }
            else if (max(d1, d2) > d)
            {
                d = max(d1, d2);
 
                if (s1.find(p[x][0]) != s1.end())
                {
                    swap(s1, s2);
                }
 
                for (auto it = s2.begin(); it != s2.end(); ++it)
                {
                    if (dist(*it, x) == d)
                    {
                        s1.insert(*it);
                        ++q[*it];
                    }
                }
                s2.clear();
                s2.insert(x);
            }
        }
 
        cout << sz(s1) + sz(s2) << "\n";
    }
 
    for (int i = 1; i <= n; ++i)
        assert(q[i] <= 1);
}
 
int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);
 
    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}