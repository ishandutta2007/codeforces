#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N (101*1000)

ll n,a[N],p_num;
pair <ll,ll> p[N];
bool mark[N];

int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==i)
		{
			cout<<"YES\n";
			for(int j=1;j<=n;j++)
				if(j!=i)
					cout<<i<<" "<<j<<"\n";
			return 0;		
		}
	}
	for(int i=1;i<=n;i++)
		if(!mark[a[i]])
		{
			mark[a[i]]=1;
			p[p_num].second=a[i];
			p[p_num].first++;
			ll v=a[a[i]];
			while(v!=a[i])
				mark[v]=1,p[p_num].first++,v=a[v];
			if(p[p_num].first%2)return cout<<"NO",0;
			p_num++;	
		}
	sort(p,p+p_num);
	if(p[0].first!=2)return cout<<"NO",0;
	cout<<"YES\n"<<p[0].second<<" "<<a[p[0].second]<<"\n";
	for(int i=1;i<p_num;i++)
	{
		cout<<p[i].second<<" "<<p[0].second<<"\n";
		ll v=a[p[i].second];
		for(int j=0;v!=p[i].second;j++)
			cout<<v<<" "<<((j%2)?p[0].second:a[p[0].second])<<"\n",v=a[v];	
	}
    return 0;
}