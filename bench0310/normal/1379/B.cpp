#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        ll l,r,m;
        cin >> l >> r >> m;
        array<ll,3> res={0,0,0};
        for(ll a=l;a<=r;a++)
        {
            ll x=(a-(m%a))%a;
            if(x<=r-l) res={a,l,l+x};
            ll y=(m%a);
            if(m-y>0&&y<=r-l) res={a,r,r-y};
        }
        for(int i=0;i<3;i++) cout << res[i] << " \n"[i==2];
    }
    return 0;
}