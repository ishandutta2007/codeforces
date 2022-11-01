#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define MOD ((ll)1e9+7)
#define INF ((ll)1e9)
#define PI ((ld)3.141592653589793)
#define N (101)

ll n,s,k[N],v[N][N],t[N][N],ans;

void solve(ll x,ll y)
{
	ll m=0;
	vector <pair<pair<ll,ll>,pair<ll,ll> > > vec;
	ll sum=0;
	for(int i=0;i<k[x];i++)vec.push_back({{sum,x},{v[x][i],t[x][i]}}),sum+=t[x][i];
	vec.push_back({{sum,x},{0,1}});sum=0;
	for(int i=0;i<k[y];i++)vec.push_back({{sum,y},{v[y][i],t[y][i]}}),sum+=t[y][i];
	vec.push_back({{sum,y},{0,1}});
	sort(vec.begin(),vec.end());
	ll last_t1=0,last_t2=0,last_v1=0,last_v2=0,last_dis1=0,last_dis2=0;
	for(int i=0;i<vec.size();i++)
	{
		ll now_time=vec[i].first.first,car=vec[i].first.second,sorat=vec[i].second.first;
		if(car==x)
		{
			ll dis1=(now_time-last_t1)*last_v1,dis2=(now_time-last_t2)*last_v2;
			if((m==2 && last_dis1+dis1<last_dis2+dis2) || (m==1 && last_dis1+dis1>last_dis2+dis2))ans++;
			last_t1=last_t2=now_time;
			last_v1=sorat;
			last_dis1+=dis1;last_dis2+=dis2;
			if(last_dis1<last_dis2)m=1;
			if(last_dis2<last_dis1)m=2;
		}
		else
		{
			ll dis1=(now_time-last_t1)*last_v1,dis2=(now_time-last_t2)*last_v2;
			if((m==2 && last_dis1+dis1<last_dis2+dis2) || (m==1 && last_dis1+dis1>last_dis2+dis2))ans++;
			last_t1=last_t2=now_time;
			last_v2=sorat;
			last_dis1+=dis1;last_dis2+=dis2;
			if(last_dis1<last_dis2)m=1;
			if(last_dis2<last_dis1)m=2;
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>s;
	for(int i=0;i<n;i++)
	{
		cin>>k[i];
		for(int j=0;j<k[i];j++)cin>>v[i][j]>>t[i][j];
	}
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			solve(i,j);
	cout<<ans;		
	return 0;
}