#include<bits/stdc++.h>
using namespace std;
struct node{
	int id,t;
}c[105];
bool cmp(node a,node b){return a.id>b.id||a.id==b.id&&a.t<b.t;}
int n,s,ans;
int main()
{
	cin>>n>>s;
	for(int i=1;i<=n;i++)
		cin>>c[i].id>>c[i].t;
	c[++n].id=s,c[n].t=0;
	sort(c+1,c+n+1,cmp);
	for(int i=2;i<=n;i++){
		ans+=c[i-1].id-c[i].id;
		ans=max(ans,c[i].t);
	}
	ans+=c[n].id;
	cout<<ans;
	return 0;
}