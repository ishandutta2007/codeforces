#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll mod=1000000007;

ll fpow(ll b,ll e)
{
    ll res=1;
    while(e)
    {
        if(e&1) res=(res*b)%mod;
        b=(b*b)%mod;
        e/=2;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        ll n,p;
        cin >> n >> p;
        set<int> two;
        map<ll,ll> now;
        for(int i=0;i<n;i++)
        {
            ll k;
            cin >> k;
            now[k]++;
        }
        if(p==1)
        {
            cout << (n%2) << "\n";
            continue;
        }
        for(auto [k,cnt]:now)
        {
            if(cnt>=p)
            {
                now[k+1]+=(cnt/p);
                two.insert(k+1);
                now[k]%=p;
            }
        }
        ll res=0;
        for(auto it=now.rbegin();it!=now.rend();it++)
        {
            auto [k,cnt]=(*it);
            if((cnt%2)==0) continue;
            if(two.find(k)==two.end())
            {
                res=fpow(p,k);
                for(it++;it!=now.rend();it++) res=(((res-fpow(p,it->first)*(it->second))%mod)+mod)%mod;
                break;
            }
            else now[k-1]+=p;
        }
        cout << res << "\n";
    }
    return 0;
}