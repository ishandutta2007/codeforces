#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;
const int maxn = 7000005;
namespace trie{
	int son[maxn][2];
	int cnt[maxn],tot=1; 
	void insert(int num,int tag) {
		int cur=1;cnt[cur]+=tag;
		for (int i=31;i>=0;i--) {
			int p=(num>>i)&1;
			if (!son[cur][p]) son[cur][p]=++tot;
			cur=son[cur][p];cnt[cur]+=tag;
		}
	}
	void query(int num) {
		int cur=1,ans=0;
		for (int i=31;i>=0;i--) {
			int p=(num>>i)&1;
			if (cnt[son[cur][p^1]]) {
				cur=son[cur][p^1];
				ans|=1<<i;
			}
			else cur=son[cur][p];
		}
		printf("%d\n",ans);
	}
}
using namespace trie;
char str[maxn];int n,num;
int main() 
{
	#ifndef ONLINE_JUDGE
		freopen("multiset.in","r",stdin);
		freopen("multiset.out","w",stdout);
	#endif
	scanf("%d",&n);insert(0,1);
	for (int i=1;i<=n;i++) {
		scanf("%s %d",str,&num);
		if (*str=='+') insert(num,1);
		if (*str=='-') insert(num,-1);
		if (*str=='?') query(num);
	}
	return 0;
}