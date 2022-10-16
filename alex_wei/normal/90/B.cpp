#include<bits/stdc++.h>
using namespace std;
int n,m,pd[102][102];
char c[102][102]; 
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>c[i][j];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			for(int k=0;k<n;k++)
				if(i!=k&&c[k][j]==c[i][j])
					pd[k][j]=pd[i][j]=1;
			for(int k=0;k<m;k++)
				if(j!=k&&c[i][j]==c[i][k])
					pd[i][j]=pd[i][k]=1;
		}
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(!pd[i][j])
				cout<<c[i][j];
	return 0;
}