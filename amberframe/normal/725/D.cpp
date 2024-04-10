#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string.h>
#include <queue>
using namespace std;

typedef long long LL;
typedef pair<int,int> mp;
#define pb push_back
const int inf = 1<<30;
const int maxn = 600005;

struct qnode {
	LL val;
	bool operator<(const qnode &v) const {
		return v.val<val;
	}
};
priority_queue<qnode> q;
struct node {
	LL w,t;
	bool operator<(const node &v) const {
		return t>v.t;
	}
}p[maxn];
int sum,ans,n,pos;LL rest;
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("ballons.in","r",stdin);
		freopen("ballons.out","w",stdout);
	#endif
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%lld %lld",&p[i].t,&p[i].w);
	sort(p+2,p+n+1);pos=2;rest=p[1].t;
	while (pos<=n&&p[pos].t>rest)
	{
		q.push((qnode){p[pos].w-p[pos].t+1});
		++pos;++sum;
	}
	ans=sum+1;
	while (pos<=n) {
		LL val=p[pos].t,minv;
		if (!q.empty()&&rest-val>=(minv=q.top().val)) {
			rest-=minv;sum--;ans=min(ans,sum+1);
			q.pop();
		}
		else {
			while (pos<=n&&p[pos].t==val) {
				q.push((qnode){p[pos].w-p[pos].t+1});
				++sum;++pos;
			}
		}
	}
	while (!q.empty()) {
		LL minv=q.top().val;
		if (rest>=minv) {
			rest-=minv;sum--;ans=min(ans,sum+1);
			q.pop();
		}
		else break;
	}
	printf("%d",ans);
	return 0;
}