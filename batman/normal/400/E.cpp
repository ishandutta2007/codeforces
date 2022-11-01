#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)101*1000)
#define K (20)

ll n,m,pre[K][N],nex[K][N],ans[K];
bool a[K][N];
set <ll> s[K];

void update1(ll i,ll x)
{
	if(a[i][x]==1)return ;
	a[i][x]=1;s[i].erase(x);
	ll p=pre[i][x],q=nex[i][x];
	ans[i]-=(q-x-1)*(q-x)/2;
	ans[i]-=(x-p-1)*(x-p)/2;
	ans[i]+=(q-p-1)*(q-p)/2;
	pre[i][q]=p;
	nex[i][p]=q;
}

void update0(ll i,ll x)
{
	if(a[i][x]==0)return ;
	a[i][x]=0;s[i].insert(x);
	ll q=*s[i].upper_bound(x),p=pre[i][q];
	ans[i]+=(q-x-1)*(q-x)/2;
	ans[i]+=(x-p-1)*(x-p)/2;
	ans[i]-=(q-p-1)*(q-p)/2;
	pre[i][q]=x;
	nex[i][x]=q;
	nex[i][p]=x;
	pre[i][x]=p;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<K;i++)
		for(int j=0;j<=n+1;j++)
			pre[i][j]=j-1,nex[i][j]=j+1,s[i].insert(j);
	for(int i=1;i<=n;i++)
	{
		ll x;
		cin>>x;
		for(int j=0;j<K;j++)
			if((x&(1<<j)))
				update1(j,i);
	}
	while(m--)
	{
		ll p,x,res=0;
		cin>>p>>x;
		for(int i=0;i<K;i++)
		{
			if(a[i][p] && !(x&(1<<i)))update0(i,p);
			else if(!a[i][p] && (x&(1<<i)))update1(i,p);
			res+=(1<<i)*ans[i];
		}
		cout<<res<<"\n";
	}
	return 0;
}