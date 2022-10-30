#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string.h>
#include <vector>
using namespace std;

typedef long long LL;
const int maxn = 100005;
LL n,num[maxn];
int cnt[maxn],top;
void dfs(int stp,LL i) {
	if (stp>top) {
		LL c=(n*n/i+i)/2;
		LL b=(n*n/i-i)/2;
		if (b>0&&&c>0&&n*n+b*b==c*c&&b<=c) {
			printf("%I64d %I64d",b,c);exit(0);
		}
		return ;
	}
	for (int j=0;j<=cnt[stp];j++,i*=num[stp])
		dfs(stp+1,i);
}
int main() {
	#ifndef ONLINE_JUDGE
		freopen("triples.in","r",stdin);
		freopen("triples.out","w",stdout);
	#endif
	scanf("%I64d",&n);
	LL cur=n;
	for (LL i=2;i*i<=cur;i++)
	if (cur%i==0) {
		num[++top]=i;
		while (cur%i==0) {
			cnt[top]+=2;cur/=i;
		}
	}
	if (cur>1) num[++top]=cur,cnt[top]=2;
	dfs(1,1ll); puts("-1");
	return 0;
}