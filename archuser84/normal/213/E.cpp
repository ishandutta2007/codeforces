#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = (l); x < (r); ++x)
#define LoopR(x, l, r) for(int x = (r)-1; x >= (l); --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << (x) << '\n', 0
#define YN(flag) ((flag)? "YES": "NO")
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
//#pragma GCC optimize ("Ofast")
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set = tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 2e5 + 10;
int a[N], b[N];
int ka[N<<1];
int ks[N<<1];
int k2[N<<1];
int n, m;

void kmp()
{
    ordered_set<int> S;
    ks[1] = 0;
    Loop(i,2,n+m+2)
    {
        S.insert(ka[i-1]);
        if(i == n+1){ks[i] = 0; S.clear(); continue;}
        ks[i] = ks[i-1]+1;
        while(ks[i] > n || (ks[i] && k2[ks[i]] != S.order_of_key(ka[i-1])))
        {
            int tmp = ks[ks[i]-1]+1;
            Loop(j,i-ks[i], i-tmp) S.erase(ka[j]);
            ks[i] = tmp;
        }
    }
}

int main()
{
    FAST;
    cin >> n >> m;
    Loop(i,0,n) cin >> a[i], a[i]--, ka[a[i]] = i;
    Loop(i,0,m) cin >> b[i], b[i]--, ka[b[i] + n + 1] = i;
    ka[n] = -1;
    ordered_set<int> S;
    Loop(i,1,n+1)
        S.insert(ka[i-1]),
        k2[i] = S.order_of_key(ka[i-1]);
    kmp();
    int ans = 0;
    Loop(i,1,n+m+2)
        if(ks[i] == n)
            ++ans;
    cout << ans << '\n';
}