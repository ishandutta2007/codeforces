#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

typedef long long LL;
const LL mod = 1e9+7;
const int maxm = 3;
const int maxn = 100005;
const int N = 100000;

LL _mat[maxm][maxm];
int n,m,beg[maxn];
struct matrix {
	int n,m;LL mat[maxm][maxm];
	void operator*=(const matrix v) {
		for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			_mat[i][j]=mat[i][j],mat[i][j]=0;

		for (int i=1;i<=n;i++)
		for (int j=1;j<=v.m;j++) {
			LL sum=0;
			for (int k=1;k<=m;k++)
				sum+=_mat[i][k]*v.mat[k][j];
   			mat[i][j]=sum%mod;
		}
		m=v.m;
	}
}trans[maxn],trans1[maxn],trans2[maxn];

namespace ST {
	LL a[maxn*4],b[maxn*4],tag[maxn*4];
	#define ls root<<1
	#define rs root<<1|1
	void update(int root) {
		a[root]=(a[ls]+a[rs])%mod;
		b[root]=(b[ls]+b[rs])%mod;
	}
	void modify(int root,LL x) {
		matrix cur;cur.n=1;cur.m=2;
		cur.mat[1][1]=a[root];
		cur.mat[1][2]=b[root];
		cur*=trans[x%N];cur*=trans1[x/N%N];
		cur*=trans2[x/N/N];
		a[root]=cur.mat[1][1];
		b[root]=cur.mat[1][2];
		tag[root]+=x;
	}
	void pushdown(int root) {
		if (LL x=tag[root]) {
			modify(ls,x);modify(rs,x);
			tag[root]=0;
		}
	}
	void modify(int root,int L,int R,int l,int r,LL x) {
		if (L>=l&&R<=r) {
			modify(root,x);return ;
		}
		int mid=L+R>>1;pushdown(root);
		if (l<=mid) modify(ls,L,mid,l,r,x);
		if (r>mid) modify(rs,mid+1,R,l,r,x);
		update(root);
	}
	LL query(int root,int L,int R,int l,int r) {
		if (L>=l&&R<=r) return a[root];
		int mid=L+R>>1;pushdown(root);
		LL res=0;
		if (l<=mid) res+=query(ls,L,mid,l,r);
		if (r>mid) res+=query(rs,mid+1,R,l,r);
		return res%mod;
	}
	void build(int root,int L,int R) {
		if (L>=R) {
			matrix cur;cur.n=1;cur.m=2;
			cur.mat[1][1]=cur.mat[1][2]=1;
			LL x=beg[L]-1;
			cur*=trans[x%N];cur*=trans1[x/N%N];
			cur*=trans2[x/N/N];
			a[root]=cur.mat[1][1];
			b[root]=cur.mat[1][2];
			return ;
		}
		int mid=L+R>>1;
		build(ls,L,mid);
		build(rs,mid+1,R);
		update(root);
	}
}
using namespace ST;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("array.in","r",stdin);
		freopen("array.out","w",stdout);
	#endif
	scanf("%d %d",&n,&m);
	trans[0].n=trans[0].m=2;
	trans[0].mat[1][1]=trans[0].mat[2][2]=1;
	trans[1].n=trans[1].m=2;
	trans[1].mat[1][2]=trans[1].mat[2][1]=trans[1].mat[2][2]=1;
	for (int i=2;i<=N;i++) {trans[i]=trans[i-1];trans[i]*=trans[1];}
	trans1[0]=trans[0];trans1[1]=trans[N];
	for (int i=2;i<=N;i++) {trans1[i]=trans1[i-1];trans1[i]*=trans1[1];}
	trans2[0]=trans[0];trans2[1]=trans1[N];
	for (int i=2;i<=N;i++) {trans2[i]=trans2[i-1];trans2[i]*=trans2[1];}

	for (int i=1;i<=n;i++) scanf("%d",&beg[i]);
	build(1,1,n);
	for (int tp,l,r,x,i=1;i<=m;i++) {
		scanf("%d %d %d",&tp,&l,&r);
		if (tp==1) scanf("%d",&x),modify(1,1,n,l,r,x);
		else printf("%lld\n",query(1,1,n,l,r));
	}
	return 0;
}