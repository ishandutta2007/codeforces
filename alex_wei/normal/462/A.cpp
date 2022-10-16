#include <bits/stdc++.h>
using namespace std;
int n;
char c[102][102]; 
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>c[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(((c[i-1][j]=='o')+(c[i][j-1]=='o')+(c[i+1][j]=='o')+(c[i][j+1]=='o'))%2)
				cout<<"NO",exit(0);
	cout<<"YES";
    return 0;
}