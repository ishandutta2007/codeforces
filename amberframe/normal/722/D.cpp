#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string.h>
#include <queue>
#include <map>
using namespace std;

typedef long long LL;
typedef pair<int,int> mp;
#define pb push_back
const int inf = 1<<30;
const int maxn = 100005;

map<int,int> arr;
int y[maxn],n,x[maxn],idx;
bool judge(int lim) {
	++idx;
	for (int i=1;i<=n;i++) {
		int num=y[i];
		while (num>lim) num>>=1;
		while (num&&arr[num]==idx) num>>=1;
		if (!num) return false;
		arr[num]=idx;x[i]=num;
	}
	return true;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("sets.in","r",stdin);
		freopen("sets.out","w",stdout);
	#endif
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&y[i]);
	int lb=0,rb=inf;
	while (rb-lb>1) {
		int mid=lb+rb>>1;
		if (judge(mid)) rb=mid;
		else lb=mid;
	}
	judge(rb);
	for (int i=1;i<=n;i++) printf("%d ",x[i]);
	return 0;
}