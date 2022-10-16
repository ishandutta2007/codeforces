#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t,n,m;
struct node{
	int v,id;
}c[1005];
bool cmp(node a,node b){return a.v<b.v;}
int main()
{
	cin>>t;
	while(t--){
		cin>>n>>m;
		int sum=0;
		for(int i=1;i<=n;i++)
			cin>>c[i].v,sum+=c[i].v*2,c[i].id=i;
		if(n>m||n==2){cout<<"-1\n";continue;}
		sort(c+1,c+n+1,cmp);
		for(int i=n+1;i<=m;i++)
			sum+=c[1].v+c[2].v;
		cout<<sum<<endl;
		for(int i=1;i<=n;i++)
			cout<<i<<" "<<(i==n?1:i+1)<<endl;
		for(int i=n+1;i<=m;i++)
			cout<<c[1].id<<" "<<c[2].id<<endl;
	}
    return 0;
}