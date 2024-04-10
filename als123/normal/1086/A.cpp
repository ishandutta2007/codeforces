#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int MAX=1e9+7;
int x[5],y[5];
int calc (int xx,int yy)
{
	int lalal=1;
	for (int u=1;u<=3;u++) lalal=lalal+abs(xx-x[u])+abs(yy-y[u]);
	return lalal;
}
void print (int xx,int yy)
{
	int nowx,nowy;
	printf("%d %d\n",xx,yy);
	nowx=xx;nowy=yy;
	while (nowx>x[1]) 	{nowx--;printf("%d %d\n",nowx,nowy);}
	while (nowx<x[1])	{nowx++;printf("%d %d\n",nowx,nowy);}
	while (nowy>y[1]) 	{nowy--;printf("%d %d\n",nowx,nowy);}
	while (nowy<y[1])	{nowy++;printf("%d %d\n",nowx,nowy);}
	nowx=xx;nowy=yy;
	while (nowx>x[2]) 	{nowx--;printf("%d %d\n",nowx,nowy);}
	while (nowx<x[2])	{nowx++;printf("%d %d\n",nowx,nowy);}
	while (nowy>y[2]) 	{nowy--;printf("%d %d\n",nowx,nowy);}
	while (nowy<y[2])	{nowy++;printf("%d %d\n",nowx,nowy);}
	nowx=xx;nowy=yy;
	while (nowx>x[3]) 	{nowx--;printf("%d %d\n",nowx,nowy);}
	while (nowx<x[3])	{nowx++;printf("%d %d\n",nowx,nowy);}
	while (nowy>y[3]) 	{nowy--;printf("%d %d\n",nowx,nowy);}
	while (nowy<y[3])	{nowy++;printf("%d %d\n",nowx,nowy);}
}
int main()
{
	for (int u=1;u<=3;u++) scanf("%d%d",&x[u],&y[u]);
	int mn=calc(x[1],y[1]);
	for (int u=1;u<=3;u++)
	for (int i=1;i<=3;i++)
	mn=min(mn,calc(x[u],y[i]));
	printf("%d\n",mn);
	for (int u=1;u<=3;u++)
	for (int i=1;i<=3;i++)
	if (calc(x[u],y[i])==mn)
	{
		print(x[u],y[i]);
		return 0;
	}
	return 0;
}