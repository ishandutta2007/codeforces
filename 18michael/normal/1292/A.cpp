#include<cstdio>
int n,q,x,y,num=0;
bool u[2][200002]={};
int main()
{
	scanf("%d%d",&n,&q);
	while(q--)scanf("%d%d",&x,&y),u[--x][y]^=1,num+=(u[x][y]?1:-1)*(u[x^1][y]+u[x^1][y-1]+u[x^1][y+1]),puts((num||u[0][1]||u[1][n])?"NO":"YES");
	return 0;
}