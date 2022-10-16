#include<bits/stdc++.h>
using namespace std;
int n,m,c[51][51];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			cin>>c[i][j];
			if((i==1||j==1||i==n||j==m)&&c[i][j])
				cout<<2,exit(0); 
		}
	cout<<4;
    return 0;
}