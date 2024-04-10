#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,x,q,ans;
double c[33][33],d[500];
char p[33][33];
string s;
int main()
{
	cin>>n>>m>>x;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>p[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			c[i][j]=1e9;
			for(int k=1;k<=n;k++)
				for(int l=1;l<=m;l++)
					if(p[k][l]=='S')
						c[i][j]=min(c[i][j],sqrt((i-k)*(i-k)+(j-l)*(j-l)));
		}
	for(char i='A';i<='Z';i++){
		d[i]=1e9;
		for(int j=1;j<=n;j++)
			for(int k=1;k<=m;k++)
				if(p[j][k]-32==i)
					d[i]=min(d[i],c[j][k]);
	}
	for(char i='a';i<='z';i++){
		d[i]=1e9;
		for(int j=1;j<=n;j++)
			for(int k=1;k<=m;k++)
				if(p[j][k]==i)
					d[i]=0;
	}
	cin>>q>>s;
	for(int i=0;i<s.size();i++)
		if(d[s[i]]==1e9)cout<<-1,exit(0);
		else ans+=d[s[i]]>x;
	cout<<ans;
    return 0;
}