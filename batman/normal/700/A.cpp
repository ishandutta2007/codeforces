#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N ((ll)301*1000)
#define INF ((ll)1e9)
#define MOD ((ll)1e9+7)
ll tavan(ll a,ll b,ll mod=MOD){ll res=1;while(b){res*=b%2?a:1;res%=mod;a*=a;a%=mod;b/=2;}return res;}

ll n,l,v1,v2,k;

bool check(ld x)
{
	ld pos=0,t=0;
	ll n2=n;
	while(n)
	{
		if(n<=k)return n=n2,t+(ld)(l-pos)/v2<=x;
		n-=k;
		ld p=((ld)(x-t)*v1*v2+v1*pos-l*v2)/((ld)v1-v2);
		t+=((ld)p-pos)/v2;
		pos+=(ld)v1*((ld)p-pos)/v2;
		ld l2=p-pos;
		t+=l2/(v1+v2);
		pos+=(ld)v1*l2/(v1+v2);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>l>>v1>>v2>>k;
	if(v2<=v1)return cout<<fixed<<setprecision(12)<<(ld)l/v1,0;
	ld le=0,ri=1e10;
	for(int i=0;i<500;i++)
	{
		ld mid=(le+ri)/2;
		//cout<<mid<<" ||||||||||||| "<<check(mid)<<"\n";
		if(check(mid))ri=mid;
		else le=mid;
	}
	cout<<fixed<<setprecision(15)<<ri<<"\n";
	
	return 0;
}