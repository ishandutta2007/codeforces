#include<cstdio>
#include<queue>
#include<algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
int n,m,k,x,y,z,s;
long long ans=1e18,ans1,ans2,ans3,tot,now1=1e19,now2=1e19,now3=1e19;
priority_queue<int>q;
int main(){
	register int i;
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=n;i++) scanf("%d",&x),now1=min(now1,x),ans1+=x;
	for(i=1;i<=m;i++) scanf("%d",&x),now2=min(now2,x),ans2+=x;
	for(i=1;i<=k;i++) scanf("%d",&x),now3=min(now3,x),ans3+=x;
	ans=min(ans1,min(ans2,ans3));
	q.push(now1);q.push(now2);q.push(now3);
	q.pop();
	tot=q.top();q.pop();tot+=q.top();//printf("%lld\n",min(ans,tot));
	printf("%lld\n",ans1+ans2+ans3-min(ans,tot)*2);
}