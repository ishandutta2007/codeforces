#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)301*1000)

ll n,p[N],ex=1,ans;
bool mark[N];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>p[i];
	for(int i=1;i<=n;i++)
	{
		ll x;
		cin>>x;
		ex^=x;
	}
	for(int i=1;i<=n;i++)
		if(!mark[i])
		{
			ll x=p[i];mark[i]=1;
			while(!mark[x])mark[x]=1,x=p[x];
			ans++;
		}
	if(ans==1)ans--;
	cout<<ans+ex;
	return 0;
}