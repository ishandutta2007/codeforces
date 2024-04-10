#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (201*1000)
#define INF ((ll)1e15)
#define MOD ((ll)1e9+7)

ll n,m,ans;
vector <pair<ll,char> > v,v2,v2_;

ll lps[N];

void calc(ll x)
{
	if(x==0)return ;
	if(!(v[x-1].second==v2[0].second && v[x-1].first>=v2[0].first))return ;
	ll p=x+(ll)v2_.size()-1;
	if(p==(ll)v.size())return ;
	if(!(v[p+1].second==v2[(ll)v2.size()-1].second && v[p+1].first>=v2[(ll)v2.size()-1].first))return ;
	ans++;
}

void solve()
{
    ll m=v2_.size(),len=0,i=1;
    lps[0]=0;
    while(i<m)
    {
       	if(v2_[i]==v2_[len])
       		len++,lps[i]=len,i++;
       	else
  	    {
         	if(len!=0)len=lps[len-1];
         	else lps[i]=0,i++;
       	}
    }
}

void KMP()
{
    ll m=v2_.size(),n=v.size(),j=0,i=0;
    solve();
    while(i<n)
    {
      	if(v2_[j]==v[i])
      		i++,j++;
      	if(j==m)
      		calc(i-j),j=lps[j-1];
     	else if (i<n && v2_[j]!=v[i])
      	{
        	if(j!=0)j=lps[j-1];
        	else i++;
      	}
    }
}

int main()
{ 
	//ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
    	string ex;
    	cin>>ex;
    	ll j=0,num=0;
    	while(ex[j]>='0' && ex[j]<='9')num=num*10+(ex[j]-'0'),j++;
    	j++;
    	
    	if(v.size() && ex[j]==v[(ll)v.size()-1].second)v[(ll)v.size()-1].first+=num;
    	else v.push_back({num,ex[j]});
	}
	for(int i=0;i<m;i++)
    {
    	string ex;
    	cin>>ex;
    	ll j=0,num=0;
    	while(ex[j]>='0' && ex[j]<='9')num=num*10+(ex[j]-'0'),j++;
    	j++;
    	if(v2.size() && ex[j]==v2[(ll)v2.size()-1].second)v2[(ll)v2.size()-1].first+=num;
    	else v2.push_back({num,ex[j]});
	}
	//cout<<"hir";
	if((ll)v2.size()==1)
	{
		for(int i=0;i<v.size();i++)
			if(v[i].second==v2[0].second && v[i].first>=v2[0].first)
				ans+=v[i].first-v2[0].first+1;
		return cout<<ans,0;
	}
	if((ll)v2.size()==2)
	{
		for(int i=0;i<(ll)v.size()-1;i++)
			if(v[i].second==v2[0].second && v[i].first>=v2[0].first && v[i+1].second==v2[1].second && v[i+1].first>=v2[1].first)
				ans++;
		return cout<<ans,0;
	}
	for(int i=1;i<(ll)v2.size()-1;i++)v2_.push_back(v2[i]);
	KMP();
	cout<<ans;
    return 0;
}