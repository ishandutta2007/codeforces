#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string.h>
#include <vector>

typedef long long LL;
#define pb push_back
using namespace std;
const int maxn = 2000005;

namespace SAM {
	int trans[maxn][26],now=1,tot=1;
	int par[maxn],len[maxn],siz[maxn],dfn[maxn];
	int que[maxn],bac[maxn];
	void insert(int w) {
		int p=now,np=++tot;
		len[np]=len[p]+1;
		while (p&&!trans[p][w])
			trans[p][w]=np,p=par[p];
		if (!p) par[np]=1;
		else {
			int q=trans[p][w];
			if (len[p]+1==len[q]) par[np]=q;
			else {
				int nq=++tot;len[nq]=len[p]+1;
				memcpy(trans[nq],trans[q],sizeof trans[q]);
				par[nq]=par[q];par[q]=nq;par[np]=nq;
				while (p&&trans[p][w]==q)
					trans[p][w]=nq,p=par[p];
			}
		}
		now=np;siz[np]++;
	}
	void getsiz(int n)
	{
		for (int i=1;i<=tot;i++) bac[len[i]]++;
		for (int i=1;i<=n;i++) bac[i]+=bac[i-1];
		for (int i=1;i<=tot;i++) que[bac[len[i]]--]=i;
		for (int i=tot;i>=1;i--) siz[par[que[i]]]+=siz[que[i]]; 
	}
}
using namespace SAM;

char str[maxn];int n,ans,slen,idx;
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("cyclical.in","r",stdin);
		freopen("cyclical.out","w",stdout);
	#endif
	scanf("%s %d",str+1,&n);
	slen=strlen(str+1);
	for (int i=1;i<=slen;i++)
		insert(str[i]-'a');
	getsiz(slen);
	for (int i=1;i<=n;i++) {
		scanf("%s",str+1);ans=0;
		slen=strlen(str+1);
		int p=1,cur=0;++idx;
		for (int j=1;j<=slen;j++)
			str[j+slen]=str[j];
		for (int j=1;j<=slen*2;j++) {
			int w=str[j]-'a';
			if (trans[p][w]) p=trans[p][w],cur++;
			else {
				while (p&&!trans[p][w]) p=par[p];
				if (!p) p=1,cur=0;
				else cur=len[p]+1,p=trans[p][w];
			}
			if (cur>=slen) {
				while (par[p]&&len[par[p]]>=slen)
					p=par[p];
				if (dfn[p]!=idx) dfn[p]=idx,ans+=siz[p];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}