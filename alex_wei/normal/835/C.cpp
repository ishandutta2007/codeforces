#include<bits/stdc++.h>
using namespace std;
int n,q,c,ori[105][105],bri[12][105][105];
int main()
{
	cin>>n>>q>>c;
	for(int i=1;i<=n;i++){
		int x,y,s;
		scanf("%d%d%d",&x,&y,&s);
		bri[s][x][y]++;
		ori[x][y]+=s;
	}
	int mx=100;
	for(int i=1;i<=mx;i++)
		for(int j=1;j<=mx;j++){
			ori[i][j]+=ori[i][j-1]+ori[i-1][j]-ori[i-1][j-1];
			for(int k=0;k<=10;k++)
				bri[k][i][j]+=bri[k][i][j-1]+bri[k][i-1][j]-bri[k][i-1][j-1];
		}
	for(int i=1;i<=q;i++){
		int t,x,y,xx,yy;
		scanf("%d%d%d%d%d",&t,&x,&y,&xx,&yy);
		int ans=ori[xx][yy]-ori[x-1][yy]-ori[xx][y-1]+ori[x-1][y-1];
		for(int j=0;j<=c;j++){
			int tmp=bri[j][xx][yy]-bri[j][x-1][yy]-bri[j][xx][y-1]+bri[j][x-1][y-1];
			int GG=(j+t)%(c+1)-j;
			ans+=tmp*GG;
		}
		printf("%d\n",ans);
	}
	return 0;
}