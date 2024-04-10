#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string.h>

using namespace std;
typedef long long LL;
const int maxn = 100005;
const int maxm = 270005;

char str[maxn],conv[maxn];
int Q,n,l,r,len,bac[maxn],s[maxn],res;
namespace ST {
	int sum[11][11][4][maxm];
	#define ls rt<<1
	#define rs rt<<1|1
	void query(int rt,int L,int R,int l,int r,int d)
	{
		if (L>=l&&R<=r) {
			for (int i=0;i<d;i++)
				res+=sum[d][i][bac[i]][rt];
			return ;
		}
		int mid=L+R>>1;
		if (l<=mid) query(ls,L,mid,l,r,d);
		if (r>mid) query(rs,mid+1,R,l,r,d);
	}
	void modify(int rt,int L,int R,int p,int c,int tag)
	{
		for (int d=1;d<=10;d++) {
			if (tag) sum[d][p%d][s[p]][rt]--;
			sum[d][p%d][c][rt]++;
		}
		if (L>=R) return ;
		int mid=L+R>>1;
		if (p<=mid) modify(ls,L,mid,p,c,tag);
		else modify(rs,mid+1,R,p,c,tag);
	}
}
using namespace ST ;
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("evolution.in","r",stdin);
		//freopen("evolution.out","w",stdout);
	#endif
	conv['A']=1;conv['G']=2;conv['C']=3;conv['T']=0;
	scanf("%s %d",str+1,&Q);n=strlen(str+1);
	for (int i=1;i<=n;i++) s[i]=conv[str[i]];
	for (int i=1;i<=n;i++) modify(1,1,n,i,s[i],0);
	for (int op,i=1;i<=Q;i++)
	{
		scanf("%d",&op);
		if (op==1) {
			scanf("%d %s",&l,str);int c=conv[*str];
			modify(1,1,n,l,c,1);s[l]=c;
		}
		else {
			scanf("%d %d %s",&l,&r,str+1);
			len=strlen(str+1);
			for (int j=l,p=1;p<=len;p++,j++)
				bac[j%len]=conv[str[p]];
			res=0;query(1,1,n,l,r,len);
			printf("%d\n",res);
		}
	}
	//cerr<<(sizeof(sum)+2*sizeof(str)+2*sizeof(bac))/1024.0/1024;
	return 0;
}