#include<bits/stdc++.h>
using namespace std;
int n,m;
char c[102][102];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>c[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<m;j++)
			if(c[i][j]!=c[i][j+1])cout<<"NO",exit(0);
	for(int i=1;i<n;i++)
		if(c[i][1]==c[i+1][1])cout<<"NO",exit(0);
	cout<<"YES"; 
	return 0;
}