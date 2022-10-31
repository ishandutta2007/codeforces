#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string.h>
#include <vector>
using namespace std;

typedef long long LL;
const int maxn = 1005005;
const int maxm = 1005;
int n,m,q,pos[maxm][maxm],cnt;
namespace pst1 {
	int tot=0;
	struct tnode {
		int lson,rson,col;
	}tree[maxn*2];
	#define now tree[root]
	#define usd tree[uroot]
	
	int query(int &root,int uroot,int L,int R,int j,int _col) {
		root=++tot;now=usd;
		if (L>=R) {
			int tmp=now.col;now.col=_col;return tmp;
		}
		int mid=L+R>>1;
		if (j<=mid) return query(now.lson,usd.lson,L,mid,j,_col);
		else return query(now.rson,usd.rson,mid+1,R,j,_col);
	}
}
namespace pst2 {
	int tot=0;
	struct tnode {
		int lson,rson,sum,rev;
	}tree[maxn*2];
	#define now tree[root]
	#define usd tree[uroot]
	void modify(int &root,int uroot,int L,int R,int i,int j,int _col,int &rt,int urt) {
		root=++tot;now=usd;
		if (L>=R) {
			if (now.rev) _col^=1;
			int ucol=pst1::query(rt,urt,1,cnt,pos[i][j],_col);
			now.sum+=(_col^now.rev)-(ucol^now.rev);
			return ;
		}
		int mid=L+R>>1;
		if (i<=mid) modify(now.lson,usd.lson,L,mid,i,j,_col,rt,urt);
		else modify(now.rson,usd.rson,mid+1,R,i,j,_col,rt,urt);
		now.sum=tree[now.lson].sum+tree[now.rson].sum;
	}
	void reverse(int &root,int uroot,int L,int R,int i,int &rt,int urt) {
		root=++tot;now=usd;
		if (L>=R) {
			now.rev^=1;now.sum=m-now.sum;rt=urt;
			return ;
		}
		int mid=L+R>>1;
		if (i<=mid) reverse(now.lson,usd.lson,L,mid,i,rt,urt);
		else reverse(now.rson,usd.rson,mid+1,R,i,rt,urt);
		now.sum=tree[now.lson].sum+tree[now.rson].sum;
	}
}
int rt1[maxn],rt2[maxn];
int main() {
	#ifndef ONLINE_JUDGE
		freopen("bookcase.in","r",stdin);
		freopen("bookcase.out","w",stdout);
	#endif
	scanf("%d %d %d",&n,&m,&q);
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
		pos[i][j]=++cnt;
	for (int op,a,b,i=1;i<=q;i++) {
		scanf("%d",&op);
		if (op==1) scanf("%d %d",&a,&b),pst2::modify(rt2[i],rt2[i-1],1,n,a,b,1,rt1[i],rt1[i-1]);
		if (op==2) scanf("%d %d",&a,&b),pst2::modify(rt2[i],rt2[i-1],1,n,a,b,0,rt1[i],rt1[i-1]);
		if (op==3) scanf("%d",&a),pst2::reverse(rt2[i],rt2[i-1],1,n,a,rt1[i],rt1[i-1]);
		if (op==4) scanf("%d",&a),rt1[i]=rt1[a],rt2[i]=rt2[a];
		printf("%d\n",pst2::tree[rt2[i]].sum);
	}	
	return 0;
}