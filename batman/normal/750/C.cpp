#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N ((ll)301*1000)
#define MOD ((ll)1e9+7)
#define INF ((ll)2e9+100)

ll n,now,x=INF,y=-INF,c[N],d[N];


int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)cin>>c[i]>>d[i];
	for(int i=0;i<n;i++)
	{
		if(d[i]==1)
			x=min(x,now);
		else 
			y=max(y,now);
		now+=c[i];
	}
	if(y==-INF)return cout<<"Infinity",0;
	if(1899-y+x<1900)return cout<<"Impossible",0;
	cout<<1899-y+now;
	return 0;
}