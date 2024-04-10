#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)40*1000*1000+1000)

ll n,ans;
int p[N];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	if(n==0)return cout<<1,0;
	long long x=n*n;
	for(ll i=0,num=n;i<=n;i++)
	{
		while(x<(1LL)*num*num+(1LL)*i*i)num--;
		ans+=2;
		if(num<i && p[num]==i)ans-=2;
		else if(num==i)ans--;
		p[i]=num;
		//cout<<i<<" "<<num<<"\n";
	}
	//cout<<ans<<"\n";
	ans=(ans-1)*4;
	cout<<ans;
	return 0;
}