#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[200005],ans,upd[200005];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		upd[i]=a[i]+(i>m?upd[i-m]:0);
	for(int i=1;i<=n;i++)
		ans+=upd[i],cout<<ans<<" ";
    return 0;
}