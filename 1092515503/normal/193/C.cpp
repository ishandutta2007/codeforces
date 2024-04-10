#include<bits/stdc++.h>
using namespace std;
const int eps=1e-9;
const int n=6;
int mx;
int gg[10][10]=
{
{},
{0,0,1,1,0,1,1},
{0,1,0,1,1,0,1},
{1,0,0,1,1,1,0},
{0,1,1,0,1,1,0},
{1,0,1,0,1,0,1},
{1,1,0,0,0,1,1}
};
int res=0x3f3f3f3f,ans[10],now[10],sum;
double g[10][10];
void work(int x){
	for(int i=1;i<=n;i++)for(int j=0;j<=n+1;j++)g[i][j]=gg[i][j];
	for(int i=1;i<=n;i++)g[i][n+1]-=g[i][0]*x;
//	for(int i=1;i<=n;i++){for(int j=1;j<=n+1;j++)printf("%lf ",g[i][j]);puts("");}puts("");
	for(int i=1;i<=n;i++){
//		printf("%d:\n",i);for(int j=1;j<=n;j++){for(int k=1;k<=n+1;k++)printf("%lf ",g[j][k]);puts("");}puts("");
		int mp=i;
		for(int j=i+1;j<=n;j++)if(fabs(g[j][i])>fabs(g[mp][i]))mp=j;
		if(mp!=i)swap(g[mp],g[i]);
		if(fabs(g[i][i])<eps)return;
		for(int j=1;j<=n;j++){
			if(j==i)continue;
//			if(g[j][i]%g[i][i])return;
			double tmp=g[j][i]/g[i][i];
			for(int k=i;k<=n+1;k++)g[j][k]-=tmp*g[i][k];
		}
	}
//	puts("IN");
	for(int i=1;i<=n;i++){
//		if(g[i][n+1]%g[i][i])return;
		now[i]=(int)(g[i][n+1]/g[i][i]+0.25);
	}
	now[0]=x,sum=0;
//	for(int i=0;i<=n;i++)printf("%d ",now[i]);puts("");
	for(int i=0;i<=n;i++)if(now[i]<0)return;
	for(int i=1;i<=n;i++){
		int ss=0;
		for(int j=0;j<=n;j++)ss+=now[j]*gg[i][j];
		if(ss!=gg[i][n+1])return;
	}
	for(int i=0;i<=n;i++)sum+=now[i];
	if(sum>=res)return;
	res=sum;
	for(int i=0;i<=n;i++)ans[i]=now[i];
}
void print(int ip){
	for(int i=0;i<=6;i++){
//		printf("%d ",ip%10);
		for(int j=1;j<=ans[i];j++)putchar(ip%10?'a':'b');
		ip/=10;
	}
	puts("");
}
int main(){
	for(int i=1;i<=n;i++)scanf("%d",&gg[i][n+1]),mx=max(mx,gg[i][n+1]);
//	for(int i=1;i<=n;i++){for(int j=1;j<=n+1;j++)printf("%2d ",gg[i][j]);puts("");}puts("");
	for(int i=0;i<=mx;i++)work(i);
	if(res==0x3f3f3f3f){puts("-1");return 0;}
	printf("%d\n",res);
	print(1110111);
	print(  11011);
	print( 101101);
	print(1001110);
	return 0;
}