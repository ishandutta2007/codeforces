#include<bits/stdc++.h>
using namespace std;
int n,m,p[128];
char s,k[102][102];
int main()
{
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>k[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(k[i][j]==s)
				for(int x=-1;x<2;x++)
					for(int y=-1;y<2;y++)
						if((abs(x)+abs(y))<2&&i+x&&j+y&&i+x<=n&&j+y<=m&&k[i+x][j+y]!='.')
							p[k[i+x][j+y]]=1;
	for(int i=1;i<128;i++)
		p[i]+=p[i-1];
	cout<<p[127]-1;
    return 0;
}