#include<bits/stdc++.h>
using namespace std;
int n,m,pd[305][305];
char c[305][305]; 
int main()
{
	cin>>n,m=n/2+1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>c[i][j];
	for(int i=1;i<=n;i++){
		pd[i][i]=pd[i][n-i+1]=1;
		if(c[i][i]!=c[m][m]||c[i][n-i+1]!=c[m][m])cout<<"NO",exit(0);
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(!pd[i][j]&&(c[i][j]!=c[1][2]||c[i][j]==c[1][1]))
				cout<<"NO",exit(0);
	cout<<"YES";
	return 0;
}