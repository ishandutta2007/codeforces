/*
Criteria:
1.read the problem carefully; WRITE DOWN SPECIAL CONSTRAINTS when the problem is long;
2.consider special situations/constraints to get observations;
3.think of everything throughout before coding;
4.return to the initial list of notifications after coding.

CONSTRAINTS:

OBSERVATIONS:

OTHER NOTIFICATIONS:

THINK CAREFULLY AND CODE DETERMINEDLY!
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,fa[100100],sum[100100],mn[100100],a[100100];
ll res;
int main(){
	scanf("%d",&n);
	for(int i=2;i<=n;i++)scanf("%d",&fa[i]);
	for(int i=1;i<=n;i++)scanf("%d",&sum[i]),mn[i]=(sum[i]==-1?0x3f3f3f3f:sum[i]);
	for(int i=n;i;i--)if(sum[fa[i]]==-1)mn[fa[i]]=min(mn[fa[i]],mn[i]);
	for(int i=1;i<=n;i++)if(mn[i]<mn[fa[i]]){puts("-1");return 0;}
	for(int i=1;i<=n;i++)if(mn[i]==0x3f3f3f3f)mn[i]=mn[fa[i]];
	for(int i=1;i<=n;i++)a[i]=mn[i]-mn[fa[i]];
	for(int i=1;i<=n;i++)res+=a[i];
	printf("%lld\n",res);
	return 0;
}