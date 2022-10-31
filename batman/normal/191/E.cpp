// I'm back ^_^
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((101*1000))

ll n,k,a[N],prt[N],fen[N];
vector <pair<ll,ll> > qu;
pair <ll,ll> prt_sort[N];

void add(ll x){for(;x<N;x+=x&-x)fen[x]++;}
ll get(ll x){ll res=0;for(;x>0;x-=x&-x)res+=fen[x];return res;}

bool check(ll x)
{
	//cout<<x<<" ";
	ll res=0;
	qu.clear();
	memset(fen,0,sizeof fen);
	if(prt[1]>=x)res++;
	for(int i=2;i<=n;i++)
	{
		qu.push_back({prt[i]-x,i-1});
		if(prt[i]>=x)res++;	
	}
	//cout<<res<<"\n";
	//for(int i=1;i<=n;i++)cout<<prt[i]<<" ";
	//cout<<"\n";
	sort(qu.begin(),qu.end());
	for(ll i=1,j=0;j<qu.size();j++)
	{
		while(prt_sort[i].first<=qu[j].first && i<=n)add(prt_sort[i].second),i++;
		res+=get(qu[j].second);
	}
	//out<<res<<"\n";
	return res>=k;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);    
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i],prt[i]=prt[i-1]+a[i],prt_sort[i]={prt[i],i};
    sort(prt_sort+1,prt_sort+n+1);
    //cout<<check(2)<<"\n";
    ll l=(ll)-1e15,r=(ll)1e15;
    while(l<r-1)
    {
    	ll mid=(l+r)/2;
    	if(check(mid))l=mid;
    	else r=mid;
	}
	cout<<l;
	return 0;
}