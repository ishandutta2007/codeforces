#include<bits/stdc++.h>
using namespace std;
int n,m,aa[11],bb[11],s,ans=100,x,y;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>s,aa[s]=1;
	for(int i=1;i<=m;i++){
		cin>>s,bb[s]=1;
		if(aa[s]&&bb[s])ans=min(ans,s);
	}
	if(ans<100)cout<<ans,exit(0);
	for(int i=9;i>0;i--)
		if(aa[i])x=i;
	for(int i=9;i>0;i--)
		if(bb[i])y=i;
	cout<<min(x,y)*10+max(x,y);
	return 0;
}