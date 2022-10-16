#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ababa ababaa
ll n,v[4002],d[4002],p[4002],vi[4002],cnt;
queue <ll> t;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>v[i]>>d[i]>>p[i],t.push(i);
	while(!t.empty()){
		ll j=t.front();
		t.pop();
		if(vi[j])continue;
		cnt++;
		int eff=v[j],poi=j;
		while(poi<=n&&eff){
			poi++;
			if(vi[poi])continue;
			p[poi]-=eff;
			eff--;
		}
		for(int i=j+1;i<=n;i++)
			if(p[i]<0&&!vi[i]){
				vi[i]=1;
				for(int k=i+1;k<=n;k++)
					p[k]-=d[i];
			}
	}
	cout<<cnt<<endl;
	for(int i=1;i<=n;i++)
		if(!vi[i])cout<<i<<" ";
	return 0;
}