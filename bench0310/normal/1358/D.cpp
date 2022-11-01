#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,x;
    cin >> n >> x;
    vector<ll> d(2*n);
    ll res=0;
    auto sum=[](ll m)->ll {if(m>=0) return (m*(m+1)/2); else return 0;};
    auto two=[&](ll m,ll k)->ll {return sum(m)-sum(m-k);};
    for(int i=0;i<n;i++)
    {
        cin >> d[i];
        if(d[i]>x) res=max(res,two(d[i],x));
        d[i+n]=d[i];
    }
    if(res>0)
    {
        cout << res << "\n";
        return 0;
    }
    ll now=0;
    ll days=0;
    ll r=0;
    for(ll l=1;l<=n;l++)
    {
        while(r<2*n&&days+d[r+1]<=x)
        {
            res=max(res,now+two(d[l-1],x-days));
            days+=d[++r];
            now+=sum(d[r]);
        }
        //cout << "l: " << l << endl;
        //cout << "r: " << r << endl;
        //cout << "days: " << days << endl;
        res=max(res,now+max(sum(x-days),two(d[l-1],x-days)));
        days-=d[l];
        now-=sum(d[l]);
    }
    cout << res << "\n";
    return 0;
}