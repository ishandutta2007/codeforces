#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    function<int(ll,ll)> win=[&](ll s,ll e)->int
    {
        if(e&1) return (1-(s&1));
        else
        {
            ll r=e/2;
            if(r<s) return (s&1);
            ll l=r/2;
            if(l<s) return 1;
            return win(s,l);
        }
    };
    auto lose=[&](ll s,ll e)->int
    {
        ll m=(e+2)/2;
        if(m<=s) return 1;
        else return win(s,m-1);
    };
    int n;
    cin >> n;
    vector<array<ll,2>> v(n);
    for(auto &[s,e]:v) cin >> s >> e;
    int w=2,l=1;
    for(int i=n-1;i>=0;i--)
    {
        auto [s,e]=v[i];
        int nw=0,nl=0;
        if((w==1&&lose(s,e))||(w==2&&win(s,e))) nw=1;
        else nw=2;
        if((l==1&&lose(s,e))||(l==2&&win(s,e))) nl=1;
        else nl=2;
        tie(w,l)={nw,nl};
    }
    cout << (w==1) << " " << (l==1) << "\n";
    return 0;
}