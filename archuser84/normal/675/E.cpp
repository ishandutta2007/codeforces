///
///    Pizza mozzarella rella rella rella... 
///

#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = (l); x < (r); ++x)
#define LoopR(x, l, r) for(int x = (r)-1; x >= (l); --x)
#define all(x) x.begin(), x.end()
#define Kill(x) exit((cout << (x) << '\n', 0))
#define YN(flag) ((flag)? "YES": "NO")
#define F first
#define S second
typedef          long long   ll;
typedef unsigned long long  ull;
typedef std::pair<int,int>  pii;
typedef std::pair<ll ,ll >  pll;
using namespace std;

const int N = 100'010;
int a[N];
ll ans[N];
int n;

int main()
{
    FAST;
    cin >> n;
    Loop(i,0,n-1) cin >> a[i]; a[n-1]=n;
    ll fans = 0;
    vector<int> st; st.push_back(n-1);
    LoopR(i,0,n-1)
    {
        int mxi = *--lower_bound(st.rbegin(), st.rend(), a[i]);
        ans[i] = ans[mxi]+(n-a[i])+(mxi-i);
        fans += ans[i];
        while(st.size() && a[i] >= a[st.back()]) st.pop_back();
        st.push_back(i);
    }
    cout << fans << '\n';
}