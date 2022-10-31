#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string.h>
#include <vector>

using namespace std;
typedef long long LL;
#define pb push_back
const int maxn = 100005;
const int inf = 1<<29;

char str[maxn];
int bac[26],n,m,odd;
namespace ST {
	int cnt[maxn*4][26],tag[maxn*4];
	#define ls root<<1
	#define rs root<<1|1
	void update(int root) {
		for (int j=0;j<26;j++)
			cnt[root][j]=cnt[ls][j]+cnt[rs][j];
	}
	void pushdown(int root,int L,int R) {
		if (tag[root]!=-1) {
			int mid=L+R>>1,col=tag[root];
			tag[ls]=tag[rs]=col;
			memset(cnt[ls],0,sizeof cnt[ls]);
			memset(cnt[rs],0,sizeof cnt[rs]);
			cnt[ls][col]=mid-L+1;
			cnt[rs][col]=R-mid;
			tag[root]=-1;
		}
	}
	void query(int root) {
		for (int j=0;j<26;j++)
			bac[j]+=cnt[root][j];
	}
		
	void build(int root,int L,int R) {
		
		if (L>=R) {
			cnt[root][str[L]-'a']++;
			tag[root]=str[L]-'a';return ;
		}
		int mid=L+R>>1;
		build(ls,L,mid);build(rs,mid+1,R);
		tag[root]=-1;update(root);
	}
	void modify(int root,int L,int R,int l,int r,int col) {
		if (L>=l&&R<=r) {
			memset(cnt[root],0,sizeof cnt[root]);
			cnt[root][col]=R-L+1;tag[root]=col;
			return ;
		}
		int mid=L+R>>1;pushdown(root,L,R);
		if (l<=mid) modify(ls,L,mid,l,r,col);
		if (r>mid) modify(rs,mid+1,R,l,r,col);
		update(root);
	}
	void query(int root,int L,int R,int l,int r) {
		if (L>=l&&R<=r) {
			query(root);return ;
		}
		int mid=L+R>>1;pushdown(root,L,R);
		if (l<=mid) query(ls,L,mid,l,r);
		if (r>mid) query(rs,mid+1,R,l,r);
	}
	void print(int root,int L,int R) {
		if (L>=R) {
			putchar(tag[root]+'a');return ;
		}
		int mid=L+R>>1;pushdown(root,L,R);
		print(ls,L,mid);print(rs,mid+1,R);
	}
}
using namespace ST;

int count_odd() {
	int res=0;
	for (int j=0;j<26;j++)
		if (bac[j]&1) ++res,odd=j;
	return res;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("torcoder.in","r",stdin);
		freopen("torcoder.out","w",stdout);
	#endif
	#ifdef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	scanf("%d %d %s",&n,&m,str+1);
	build(1,1,n);
	for (int l,r,i=1;i<=m;i++) {
		memset(bac,0,sizeof bac);
		scanf("%d %d",&l,&r);
		query(1,1,n,l,r);
		int res=count_odd();
		if (res>1) continue;
		if (res!=(r-l+1)%2) continue;
		for (int j=0;j<26;l+=bac[j]/2,r-=bac[j]/2,j++)
		if (bac[j]>1) {
			modify(1,1,n,l,l+bac[j]/2-1,j);
			modify(1,1,n,r-bac[j]/2+1,r,j);
		}
		if (res&1) modify(1,1,n,l,r,odd);
	}
	print(1,1,n);puts(""); 
	return 0;
}