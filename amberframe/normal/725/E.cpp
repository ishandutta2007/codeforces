#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string.h>
#include <vector>
using namespace std;

typedef long long LL;
typedef pair<int,int> mp;
#define pb push_back
const int inf = 1<<30;
const int maxn = 200005;
const int maxm = maxn*40;

int c,a[maxn],n,nex[maxn],cnt[maxn];
bool judge(int t) {
	int pos=a[n],num=c;
	bool tag=true;
	while (pos) {
		if (tag&&pos<t) {
			if (num>=t) num-=t;
			tag=false;
		}
		else {
			if ((LL)cnt[pos]*pos<=num) {
				num-=cnt[pos]*pos;
				pos=nex[pos-1];
			}
			else {
				num%=pos;pos=nex[num];
			}
		}
	}
	return num;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("money.in","r",stdin);
		freopen("money.out","w",stdout);
	#endif
	scanf("%d %d",&c,&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++) {
		nex[a[i]]=a[i];++cnt[a[i]];
	}
	for (int i=1;i<=c;i++)
	if (!nex[i]) nex[i]=nex[i-1];
	for (int i=1;i<=c;i++)
	if (judge(i)) {printf("%d",i);return 0;}
	puts("Greed is good");
	return 0;
}