#include <bits/stdc++.h>
using namespace std;
#define ll int
#define INF ((ll)1e9+7)
#define N 101*1000
ll n,q,a[N],seg_gcd[N*10];
pair <ll,int> seg_min[N*10];

void build_min(ll id,ll b,ll e)
{
	if(e==b)
	{
		seg_min[id]={a[b],1};
		return ;
	}
	
	ll l=id<<1,r=l|1,mid=e+b>>1;
	build_min(l,b,mid),build_min(r,mid+1,e);
	
	if(seg_min[l].first<seg_min[r].first)
		seg_min[id]=seg_min[l];
	else if(seg_min[l].first>seg_min[r].first)
		seg_min[id]=seg_min[r];
	else
		seg_min[id]={seg_min[l].first,seg_min[l].second+seg_min[r].second};		
	//seg_min[id]=((seg_min[l].first<seg_min[r].first)?seg_min[l]:((seg_min[l].first>seg_min[r].first)?seg_min[r]:{seg_min[l].first,seg_min[l].second+seg_min[r].second}));
}

void build_gcd(ll id,ll b,ll e)
{
	if(b==e)
	{
		seg_gcd[id]=a[b];
		return ;
	}
	
	ll l=id<<1,r=l|1,mid=e+b>>1;
	build_gcd(l,b,mid),build_gcd(r,mid+1,e);
	
	seg_gcd[id]=__gcd(seg_gcd[l],seg_gcd[r]);
	
}

pair <ll,int> query_min(ll i,ll j,ll id,ll b,ll e)
{
	if(i>e || j<b)
		return {INF,0};
	if(i==b && j==e)
		return seg_min[id];
		
	ll l=id<<1,r=l|1,mid=e+b>>1;
	
	if(i<=mid && j<=mid)
		return query_min(i,j,l,b,mid);
	if(i>mid && j>mid)
		return query_min(i,j,r,mid+1,e);
	pair <ll,int> p1=query_min(i,mid,l,b,mid),p2=query_min(mid+1,j,r,mid+1,e);
	if(p1.first<p2.first)
		return p1;
	if(p1.first>p2.first)
		return p2;
	return {p1.first,p2.second+p1.second};				
		
}

ll query_gcd(ll i,ll j,ll id,ll b,ll e)
{
	if(i>e || j<b)
		return INF;
	if(i==b && j==e)
		return seg_gcd[id];
		
	ll l=id<<1,r=l|1,mid=e+b>>1;
	
	if(i<=mid && j<=mid)
		return query_gcd(i,j,l,b,mid);
	if(i>mid && j>mid)
		return query_gcd(i,j,r,mid+1,e);		
	return __gcd(query_gcd(i,mid,l,b,mid),query_gcd(mid+1,j,r,mid+1,e));
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)
    	cin>>a[i];
    build_min(1,0,n-1);	
    //cerr<<"min\n";
    build_gcd(1,0,n-1);
    //cerr<<"gcd\n";
    cin>>q;
	while(q--)
	{
		ll i,j;
		cin>>i>>j;
		i--,j--;
		pair <ll,int> p=query_min(i,j,1,0,n-1);
		//cerr<<p.first<<" "<<p.second<<" ";
		ll GcD=query_gcd(i,j,1,0,n-1);
		//cerr<<GcD<<"\n";	
		cout<<j-i+1-((GcD==p.first)?p.second:0)<<"\n";
	}	
    return 0;
}