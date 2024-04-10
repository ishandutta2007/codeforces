#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--) 
#define ll __int128
const int P=998244353;
map<int,int> M;
const int N=1e6+100;
set<pair<pair<int,int>,int> > S;
ll a[N];
int n,m;
struct sgt{
  ll c1[N],c2[N]; 
  inline void update(ll x,ll k)
  {
    ll i=x;
    while(x<=n)
    {
        c1[x]+=k;
        c2[x]+=i*k;
        x+=x&-x;
    }
    return;
  }
  inline ll sum(ll x)
  {
    ll ans=0;
    ll i=x;
    while(x>0)
    {
        ans+=c1[x]*(i+1);
        ans-=c2[x];
        x-=x&-x;
    }
    return ans;
  }
   inline void change(int x,int y,ll z)
   {
  //     cerr<<x<<" "<<y<<endl;
      update(x,z);
      update(y+1,-z);
   }
   ll query(int x)
   {
      return sum(x)-sum(x-1);
   }
}SS;
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	S.insert(make_pair(make_pair(1,n),1));
    while (m--)
    {
    	char s[10];
    	cin>>s;
    	int x,y,z;
    	if (s[0]=='C')
    	{
    		cin>>x>>y>>z;
    		auto it=S.upper_bound(make_pair(make_pair(x,100000000),100000000));it--;
    		auto it2=it;
    		while (it!=S.end()&&((it->first).second)<=y)
    		{
    			it2=it; it2++;
    			if ((it->first).first<x)
    			{
    				SS.change(x,it->first.second,a[it->second]);
    				S.insert(make_pair(make_pair(it->first.first,x-1),it->second));
    				S.erase(it);
    			} else
    			{
    			    SS.change(it->first.first,it->first.second,a[it->second]);
    			    S.erase(it);
    		    }
    		    it=it2;
    		}
    		if (it!=S.end()&&it->first.second>y&&it->first.first<=y)
    		{
    			if ((it->first).first<x)
    			{
    				S.insert(make_pair(make_pair(it->first.first,x-1),it->second));
    			}
    		   SS.change(max(x,it->first.first),y,a[it->second]);
    		   S.insert(make_pair(make_pair(y+1,it->first.second),it->second));
    		   S.erase(it);
    	    }
    	    S.insert(make_pair(make_pair(x,y),z));
    	    SS.change(x,y,-a[z]);
    	} else 
    	if (s[0]=='A')
    	{
    		cin>>x>>y;
    		a[x]+=y;
    	} else
    	if (s[0]=='Q')
    	{
    		cin>>x;
    		auto it=S.upper_bound(make_pair(make_pair(x,100000000),100000000));it--;
    		long long ans=a[it->second]+SS.query(x);
    		cout<<ans<<endl;
    	}
    }
	return 0;
}