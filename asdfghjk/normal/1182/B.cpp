#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int h,w,i,j,k,x,y,z,f[10][5]={{-1,0},{1,0},{0,-1},{0,1}},c[10];
bool e[10];
char s[505][505];
int main()
{
	scanf("%d%d",&h,&w);
	for(i=1;i<=h;++i)
		scanf("%s",s[i]+1);
	for(i=1;i<=h;++i)
		for(j=1;j<=w;++j)
			if(s[i][j]=='*')
			{
				z=0;
				for(k=0;k<4;++k)
				{
					x=i+f[k][0],y=j+f[k][1];
					if(x>=1&&x<=h&&y>=1&&y<=w&&s[x][y]=='*')
						++z,e[k]=true;
					else
						e[k]=false;
				}
				++c[z];
				if(z==2&&!(e[0]&&e[1]||e[2]&&e[3]))
				{
					printf("NO");
					return 0;
				}
			}
	if(c[4]==1&&c[1]==4&&c[3]==0&&c[0]==0)
		printf("YES");
	else
		printf("NO");
	return 0;
}