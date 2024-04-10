#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,a[51][51],b[51][51],x[2550],y[2550],ans;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(a[i][j]&&a[i+1][j]&&a[i][j+1]&&a[i+1][j+1])
				x[++ans]=i,y[ans]=j,b[i][j]=b[i][j+1]=b[i+1][j]=b[i+1][j+1]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(a[i][j]!=b[i][j])
				cout<<-1,exit(0);
	cout<<ans<<endl;
	for(int i=1;i<=ans;i++)
		cout<<x[i]<<" "<<y[i]<<endl;
    return 0;
}