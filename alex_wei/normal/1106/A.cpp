#include<bits/stdc++.h>
using namespace std;
int n,s;
char c[502][502];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>c[i][j];
	for(int i=2;i<n;i++)
		for(int j=2;j<n;j++)
			if(c[i][j]=='X'&&c[i-1][j-1]=='X'&&c[i-1][j+1]=='X'&&c[i+1][j-1]=='X'&&c[i+1][j+1]=='X')
				s++;
	cout<<s;
	return 0;
}