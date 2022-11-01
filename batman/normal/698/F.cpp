#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)1001*1000)
#define MOD ((ll)1e9+7)

int n,a[N],cnt[N],base[N],cnt_base[N],where[N],here[N];
ll fac[N];
vector <int> divi[N];
bool mark[N];

int main()
{
	scanf("%d",&n);
	cnt[1]=fac[0]=1;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),fac[i]=(fac[i-1]*i)%MOD,base[i]=1;
	divi[1].push_back(1);
	for(int i=2;i<=n;i++)
		if(!mark[i])
		{
			cnt[n/i]++;
			for(int j=i;j<=n;j+=i)
				mark[j]=1,divi[j].push_back(i),base[j]*=i;
		}
	ll ans=1;
	for(int i=1;i<=n;i++)cnt_base[base[i]]++;
	for(int i=1;i<=n && ans;i++)
	{
		if(!a[i])continue;
		if(divi[i].size()!=divi[a[i]].size()){ans=0;break;}
		for(int j=0;j<divi[i].size();j++)
		{
			int v=divi[i][j],u=divi[a[i]][j];
			int p_v=(v==1?1:n/v),p_u=(u==1?1:n/u);
			if(p_v!=p_u)
			{
				ans=0;
				break;
			}
			if(where[v] && where[v]!=u){ans=0;break;}
			if(here[u] && here[u]!=v){ans=0;break;}
			if(where[v]!=u)where[v]=u,here[u]=v,cnt[p_v]--;
		}
		if(!ans)break;
		cnt_base[base[i]]--;
	}
	for(int i=1;i<=n;i++)ans*=(fac[cnt[i]]*fac[cnt_base[i]])%MOD,ans%=MOD;
	cout<<ans;
	return 0;
}