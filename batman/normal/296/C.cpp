#include <bits/stdc++.h>
using namespace std;
#define N (101*1000)
typedef long long ll;

struct op{
	ll l,r,d,num;
};
ll n,m,k,ans[N],tmp[N];
op a[N];
int main()
{
	cin>>n>>m>>k;
	for(int i=0;i<n;i++)cin>>tmp[i];
	for(int i=0;i<m;i++)cin>>a[i].l>>a[i].r>>a[i].d,a[i].num=0;
	for(int i=0;i<k;i++)
	{
		ll x,y;
		cin>>x>>y;
		a[x-1].num++;
		a[y].num--;
	}
	for(int i=0;i<m;i++)
	{
		if(i)a[i].num+=a[i-1].num;
		ans[a[i].l-1]+=a[i].d*a[i].num;
		ans[a[i].r]-=a[i].d*a[i].num;
	}
	for(int i=0;i<n;i++)
	{
		if(i)ans[i]+=ans[i-1];
		cout<<ans[i]+tmp[i]<<" ";
	}
    return 0;
}