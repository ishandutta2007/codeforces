#include<bits/stdc++.h>
using namespace std;
char s;
int u=115,d,l=115,r,n,m; 
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			cin>>s;
			if(s=='B')u=min(u,i),d=max(d,i),l=min(l,j),r=max(r,j);
		}
	cout<<(u+d)/2<<" "<<(l+r)/2;
	return 0;
}