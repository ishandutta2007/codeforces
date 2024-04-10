#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <iostream>
using namespace std;
const int maxn = 600005;
int Q[maxn],n,q,cnt,ans;
int cur[maxn],nex[maxn],pos[maxn];
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("thor.in","r",stdin);
		freopen("thor.out","w",stdout);
	#endif
	scanf("%d %d",&n,&q);
	for (int i=1;i<=n;i++)
		cur[i]=pos[i]=i;
	cnt=n;cur[0]=n;
	for (int tp,x,i=1;i<=q;i++) {
		scanf("%d %d",&tp,&x);
		if (tp==1) {
			Q[++cnt]=x;++ans;
			nex[pos[x]]=cnt;pos[x]=cnt;
		}
		else if (tp==2) {
			while (nex[cur[x]]) {
				int j=cur[x]=nex[cur[x]];
				if (Q[j]) {Q[j]=0;ans--;}
			}
		}
		else {
			while (cur[0]<n+x) {
				int j=++cur[0];
				if (Q[j]) {Q[j]=0;ans--;}
			}
		}
		printf("%d\n",ans);
	}	
	return 0;
}