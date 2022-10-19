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
const int N = 100005;
 
int n;
int a[N];
 
unordered_map<int, ll> t[N];
void ubdy(int x, int y, int z)
{
    while (y <= n)
    {
        t[x][y] += z;
        y += (y & (-y));
    }
}
void ubdx(int x, int y, int z)
{
    while (x <= n)
    {
        ubdy(x, y, z);
        x += (x & (-x));
    }
}
 
ll qryy(int x, int y)
{
    ll ans = 0;
    while (y)
    {
        if (t[x].find(y) != t[x].end())
            ans += t[x][y];
        y -= (y & (-y));
    }
    return ans;
}
 
ll qryx(int x, int y)
{
    ll ans = 0;
    while (x)
    {
        ans += qryy(x, y);
        x -= (x & (-x));
    }
    return ans;
}
 
void ubd(int x1, int x2, int y1_, int y2, int z)
{
    if (x1 > x2)
        return;
    if (y1_ > y2)
        return;
    ubdx(x1, y1_, z);
    ubdx(x2 + 1, y1_, -z);
    ubdx(x1, y2 + 1, -z);
    ubdx(x2 + 1, y2 + 1, z);
}
 
set<int> s[N];
 
void ave(int i)
{
    auto it = s[a[i]].upper_bound(i);
    int ur = *it;
    --it;
    int ul = *it;
    s[a[i]].insert(i);
 
    ubd(1, ul, i, ur - 1, (i - ul));
    ubd(ul + 1, i, ur, n, (ur - i));
}
 
void han(int i)
{
    s[a[i]].erase(i);
    auto it = s[a[i]].upper_bound(i);
    int ur = *it;
    --it;
    int ul = *it;
 
    ubd(1, ul, i, ur - 1, -(i - ul));
    ubd(ul + 1, i, ur, n, -(ur - i));
}
 
void solv()
{
    int qq;
    cin >> n >> qq;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
 
    for (int i = 1; i <= n; ++i)
    {
        s[i].insert(0);
        s[i].insert(n + 1);
    }
 
    for (int i = 1; i <= n; ++i)
        ave(i);
 
    while (qq--)
    {
        int ty;
        cin >> ty;
        if (ty == 1)
        {
            int i, x;
            cin >> i >> x;
            han(i);
            a[i] = x;
            ave(i);
        }
        else
        {
            int x, y;
            cin >> x >> y;
            cout << qryx(x, y) << "\n";
        }
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