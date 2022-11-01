#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N ((ll)101*1000)

ll n,m,a[N],h[N],l[N],r[N],b[N],part0[N];
ld part[N],ans;
pair <ll,ll> c[N];



int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<N;i++)part[i]=1;
	for(int i=0;i<n;i++)
		cin>>a[i]>>h[i]>>l[i]>>r[i];
	for(int i=0;i<m;i++)
		cin>>c[i].first>>c[i].second;
	sort(c,c+m);
	for(int i=0;i<m;i++)b[i]=c[i].first;
	for(int i=0;i<n;i++)
	{
		ll ex;
		
		ex=upper_bound(b,b+m,a[i])-b;
		if(r[i]!=100)part[ex]*=(ld)(100-r[i])/100;
		else part0[ex]++;
		ex=upper_bound(b,b+m,a[i]+h[i])-b;
		if(r[i]!=100)part[ex]/=(ld)(100-r[i])/100;
		else part0[ex]--;
		
		ex=lower_bound(b,b+m,a[i])-b;
		if(l[i]!=100)part[ex]/=(ld)(100-l[i])/100;
		else part0[ex]--;
		ex=lower_bound(b,b+m,a[i]-h[i])-b;
		if(l[i]!=100)part[ex]*=(ld)(100-l[i])/100;
		else part0[ex]++;
	}
	for(int i=0;i<m;i++)
	{
		if(i)part[i]*=part[i-1];
		if(i)part0[i]+=part0[i-1];
		if(!part0[i])ans+=(ld)c[i].second*part[i];
	}
	cout<<fixed<<setprecision(15)<<ans;
	return 0;
}