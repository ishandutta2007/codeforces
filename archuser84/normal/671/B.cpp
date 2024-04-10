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
//#pragma GCC optimize ("O0")
using namespace std;

#define int ll
int32_t main()
{
    FAST;
    int n, k;
    ll sum = 0;
    cin >> n >> k;
    map<int, int> M;
    Loop(i,0,n)
    {
        int x;
        cin >> x;
        M[x]++;
        sum += x;
    }
    map<int, int> m = M;
    int rem = k;
    auto it = m.begin();
    int mn;
    while(1)
    {
        mn = it->F;
        auto it2 = it; it2++;
        if(it2 == m.end()) break;
        if((it2->F - it->F)*it->S <= rem)
        {
            rem -= (it2->F - it->F)*it->S;
            it2->S += it->S;
        }
        else
        {
            mn = it->F + rem/it->S;
            break;
        }
        it++;
    }
    m = M;
    rem = k;
    it = m.end(); it--;
    int mx;
    while(1)
    {
        mx = it->F;
        auto it2 = it;
        if(it2 == m.begin()) break;
        it2--;
        if((it->F - it2->F)*it->S <= rem)
        {
            rem -= (it->F - it2->F)*it->S;
            it2->S += it->S;
        }
        else
        {
            mx = it->F - rem/it->S;
            break;
        }
        it--;
    }
    mn = min(mn, sum/n);
    mx = max(mx, (sum+n-1)/n);
    cout << mx-mn << '\n';
}