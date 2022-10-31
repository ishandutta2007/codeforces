#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string.h>

using namespace std;
typedef long long LL;
const int maxn = 2000005;
const int N = 2e6;

char str[maxn],op[maxn];int n,len,par[maxn];bool vis[maxn];
int findp(int t) {return par[t]?par[t]=findp(par[t]):t;}
void merge(int u,int v) {u=findp(u);v=findp(v);if (u!=v) {if (u>v) par[v]=u;else par[u]=v;}}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("reconstruction.in","r",stdin);
		//freopen("reconstruction.out","w",stdout);
	#endif
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		int m,x;scanf("%s %d",op,&m);len=strlen(op);
		while (m--) {
			scanf("%d",&x);
			for (int o=vis[x]?findp(x)+1:x;o<x+len;) {
				str[o]=op[o-x],vis[o]=true,merge(o,x);
				o=vis[o+1]?findp(o+1)+1:o+1;
			}
		}
	}
	int l=N;while (!str[l]) l--;
	for (int i=1;i<=l;i++)
		printf("%c",str[i]?str[i]:'a');
	return 0;
}