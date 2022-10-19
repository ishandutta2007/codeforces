#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = l; x < r; ++x)
#define LoopR(x, l, r) for(int x = r-1; x >= l; --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << x << '\n', 0
#define YN(flag) (flag? "YES": "NO")
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
//#pragma GCC optimize ("O3")
using namespace std;

const int N = 200'010;
char a[N];
int n, k;

void solve()
{
    cin >> n >> k;
    cin >> a;
    int ans=0;
    vector<int> V;
    int l = -2*N; V.push_back(-l);
    Loop(i,0,n)
    {
        if(a[i] == 'W')
            ans += 1,
            V.push_back(i-l-1),
            //cout << V.back() << "!\n",
            l = i;
    }
    if(ans == 0)
    {
        cout << max(2*k-1, 0) << '\n';
        return;
    }
    if(k+ans >= n)
        {cout << 2*n-1 << '\n'; return;}

    sort(all(V));
    for(int i = 0; i < V.size(); ++i)
    {
        if(k < V[i])
        {
            ans += 2*k;
            break;
        }
        ans += 2*V[i] + 1;
        k -= V[i];
    }
    cout << ans << '\n';
}

int main()
{
    FAST;
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}