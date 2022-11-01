#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
#define INF ((ll)1e14)
#define N (3001*1000)

ll n,d;
bool mark[N];
pair <ll,ll> a[N];
vector <pair<ll,ll> > ans;
priority_queue <ll> s;

int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    scanf("%d%d",&n,&d);
    for(int i=0;i<n;i++)
        scanf("%d%d",&a[i].first,&a[i].second);
    sort(a,a+n);
    for(int i=0;i<n;i++)
    {
        s.push(-a[i].second);
        while(s.size() && (s.size()>d || -s.top()<a[i].first))s.pop();
        if(s.size()<d)continue;
        ans.push_back({a[i].first,-s.top()});
    }
    for(int i=0;i<(ll)ans.size();i++)
        mark[i]=1;
    ll res=ans.size();  
    for(int i=0;i<(ll)ans.size()-1;i++)
    {
        if(ans[i].second>=ans[i+1].first)
            ans[i+1].first=ans[i].first,mark[i]=0,res--;
    }
    printf("%d\n",res);
    for(int i=0;i<(ll)ans.size();i++)
        if(mark[i])
            printf("%d %d\n",ans[i].first,ans[i].second);
    
    
    return 0;
}