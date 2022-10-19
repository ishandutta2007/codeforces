#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = (l); x < (r); ++x)
#define LoopR(x, l, r) for(int x = (r)-1; x >= (l); --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << (x) << '\n', 0
#define YN(flag) ((flag)? "YES": "NO")
#define ll int64_t
#define ull uint64_t
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
//#pragma GCC optimize ("O0")
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set = tree < T ,  null_type ,  less<T> ,  rb_tree_tag ,  tree_order_statistics_node_update >;

const int N = 2e5 + 10;
int a[N];
pii b[N];
pair<pii, int> q[N];
int ans[N];

int main()
{
    FAST;
    int n;
    cin >> n;
    Loop(i,0,n)
    {
        cin >> a[i];
        b[i] = {a[i], ~i};
    }
    sort(b, b+n, greater<pii>());
    int m;
    cin >> m;
    Loop(i,0,m)
    {
        cin >> q[i].F.F >> q[i].F.S; q[i].S = i;
    }
    sort(q, q+m);
    int k = 0;
    ordered_set<int> s;
    Loop(i,0,m)
    {
        while(k < q[i].F.F)
        {
            s.insert(~b[k].S);
            ++k;
        }
        ans[q[i].S] = a[*s.find_by_order(q[i].F.S-1)];
    }
    Loop(i,0,m) cout << ans[i] << '\n';
}