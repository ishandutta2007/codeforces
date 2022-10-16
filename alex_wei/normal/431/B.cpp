#include <bits/stdc++.h>
using namespace std;
int g[6][6],s;
int main()
{
	for(int i=1;i<6;i++)
		for(int j=1;j<6;j++)
			cin>>g[i][j];
	for(int a=1;a<6;a++)
		for(int b=1;b<6;b++)
			for(int c=1;c<6;c++)
				for(int d=1;d<6;d++)
					for(int e=1;e<6;e++)
						if(a+b+c+d+e==15&&a*b*c*d*e==120)
							s=max(s,g[a][b]+g[b][a]+g[c][d]*2+g[d][c]*2+g[b][c]+g[c][b]+g[d][e]*2+g[e][d]*2);
	cout<<s;
    return 0;
}