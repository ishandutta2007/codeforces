#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=1000005;
char ss[N];
int n,nn;
int v[N],tmp[N];
int a[N];
bool cmp1 (int x,int y)	{return ss[x]<ss[y];}
int kk;
bool cmp  (int x,int y)	
{
	return v[x]==v[y] 
	? v[x^kk]<v[y^kk] 
	: v[x]<v[y];
}
int main()
{
	scanf("%d",&n);
	scanf("%s",ss);
	nn=(1<<n);
	for (int u=1;u<=nn;u++)	a[u]=u-1;
	sort(a+1,a+1+nn,cmp1);
	for (int u=1;u<=nn;u++) v[a[u]]=v[a[u-1]]+(ss[a[u]]!=ss[a[u-1]]);
//	for (int u=0;u<nn;u++) printf("%d ",v[u]);printf("\n");
	for (int k=1;k<=n;k++)
	{
		kk=(1<<k-1);
		sort(a+1,a+1+nn,cmp);
		for (int u=1;u<=nn;u++) tmp[a[u]]=tmp[a[u-1]]+cmp(a[u-1],a[u]);
		for (int u=0;u<nn;u++) v[u]=tmp[u];
	}
	for (int u=0;u<nn;u++)	printf("%c",ss[u^a[1]]);
	return 0;
}