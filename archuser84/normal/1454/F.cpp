#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = l; x < r; ++x)
#define LoopR(x, l, r) for(int x = (r)-1; x >= l; --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << (x) << '\n', 0
#define YN(flag) ((flag)? "YES": "NO")
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
//#pragma GCC optimize ("O3")
using namespace std;

const int N = 200'010;
const int logN = 19;
int a[N];
int n;

template<class T, class cmp>
struct rmq
{
    T b[logN][N];
    int n;

    inline const T& KO(const T& a, const T& b)
    {
        return cmp()(a, b)? a: b;
    }

    void make(T* begin, T* end)
    {
        n = end - begin;
        Loop(i,0,n+2)
            Loop(j,0,logN)
                b[j][i] = 0;
        n = 0;
        for(T* x = begin; x != end; ++x)
            b[0][n++] = *x;
        for(int k = 1; k < logN; ++k)
            for(int i = 0; i < n; ++i)
                b[k][i] = KO(b[k-1][i], b[k-1][i + (1 << (k-1))]);
    }

    T get(int l, int r)
    {
        int s = r-l;
        int k = 31 - __builtin_clz(s);
        return KO(b[k][l], b[k][r-(1<<k)]);
    }
};

rmq<int, less<int>> mn;
rmq<int, greater<int>> mx;

bool check(int x, int y, int z)
{
    if(x <= 0 || y <= 0 || z <= 0) return 0;
    return mx.get(0, x) == mn.get(x, x+y) && mn.get(x, x+y) == mx.get(x+y, n);
}

vector<pii> q;
set<int> q2;

void solve()
{
    cin >> n;
    q.clear(); q2.clear(); q2.insert(n);
    Loop(i,0,n)
        cin >> a[i],
        //a[i] = i,
        q.push_back({a[i], i});
    sort(all(q), greater<pii>());
    mn.make(a, a+n);
    mx.make(a, a+n);
    for(int x1 = 0; x1 < n; ++x1)
    {
        int k = mx.get(0, x1+1);
        while(q.size() && q.back().F < k)
        {
            auto t = q.back();
            q.pop_back();
            if(t.S <= x1) continue;
            q2.insert(t.S);
        }
        q2.erase(x1);
        int j = *q2.begin();
        if(check(x1+1, j-x1-1, n-j))
        {
            cout << "YES\n";
            cout << x1+1 << ' ' << j-x1-1 << ' ' << n-j << '\n';
            return;
        }
        if(check(x1+1, j-x1-2, n-j+1))
        {
            cout << "YES\n";
            cout << x1+1 << ' ' << j-x1-2 << ' ' << n-j+1 << '\n';
            return;
        }
    }
    cout << "NO\n";
}

int main()
{
    FAST;
    int t;
    cin >> t;
    while(t--)
        solve();
}