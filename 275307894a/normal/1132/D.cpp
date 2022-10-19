#include<cstdio>
#include<queue>
using namespace std;
int n,m,k,x,y,z,ans,tot,pus;
long long l,r,mid,a[200039],b[200039];
struct yyy{
	long long x,y;
	bool operator <(const yyy &a)const{
		return x/y>a.x/a.y;
	}
}tmp;
priority_queue<yyy> q;
inline int check(long long mid){
	register int i;
	while(!q.empty()) q.pop();
	for(i=1;i<=n;i++) if(a[i]/b[i]<m)q.push((yyy){a[i],b[i]});
	for(i=1;i<=m;i++){
		if(q.empty()) return 1;
		tmp=q.top();
		q.pop();
	//	printf("%lld %lld %lld\n",mid,tmp.x,tmp.y);
		if(tmp.x/tmp.y<i-1) return 0;
		tmp.x+=mid;
		if(tmp.x/tmp.y<m)q.push(tmp);
	}
	return 1;
}
int main(){
	register int i;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(i=1;i<=n;i++) scanf("%lld",&b[i]);
	l=-1;r=2e12+1;
	while(l+1<r){
		mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid;
	}
	if(l==2e12) printf("-1\n");
	else printf("%lld\n",r);
}