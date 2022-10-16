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
		for(int j=1;j<=m;j++)
			if(c[i][j]!='*'){
				int cnt=0;
				for(int k=-1;k<2;k++)
					for(int l=-1;l<2;l++)
						cnt+=(c[k+i][l+j]=='*');
				if(c[i][j]=='.')c[i][j]='0';
				if(cnt!=c[i][j]-'0')
					cout<<"NO",exit(0);
			}
	cout<<"YES";
	return 0;
}