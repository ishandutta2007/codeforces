#include <bits/stdc++.h>
using namespace std;
#define INF ((ll)1e15)
#define MOD ((ll)1e9+7)
#define N (301*1000)
#define ll long long
#define ld long double

ll x;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>x;
    //cout<<l<<endl;
    vector <pair<ll,ll> > ans;
    for(ll a=1;a<=(ll)3e6;a++)
    {
        ll ex=a*(a-1)*(2*a-1)/6-(a*a*(a-1))/2;
        ll p=a*a-a*(a-1)/2;
        
        if((x-ex)%p==0 && (x-ex)/p>=a)
        {
            ll ex2=(x-ex)/p;
            ans.push_back({a,ex2});
            if(ex2!=a)
                ans.push_back({ex2,a});
        }
    }
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<"\n";
    for(int i=0;i<ans.size();i++)cout<<ans[i].first<<" "<<ans[i].second<<"\n";  
    return 0;
}