#include<cstdio>
#include<cmath>
#include<map>
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
int n,m,k,z,f[100039],s[100039],d[100039],head,dh,t,sh;
map<long long,int> q;
long long x,y,now,tot,pus,ans,flag;
int main(){
//	freopen("1.in","r",stdin);
	register int i,j;
	for(i=2; i*i<=1e9; i++) {
		if(!f[i]) s[++head]=i;
		for(j=1; j<=head&&i*s[j]<=100000; j++) {
			f[i*s[j]]=1;
			if(i%s[j]==0) break;
		}
	}
	scanf("%d",&t);
	while(t--){
		scanf("%lld%lld",&x,&y);now=y;
		dh=sh=0;pus=1e18;
		for(i=1;s[i]*s[i]<=y&&i<=head;i++){
			if(now%s[i]==0){
				d[++dh]=s[i];
				while(now%s[i]==0)q[s[i]]++,now/=s[i],sh++;
			}
		} 
		if(now!=1)q[now]++,d[++dh]=now,sh++;
		now=x;
		for(i=1;i<=dh;i++){
			if(x%d[i]==0){
				ans=0;
				while(x%d[i]==0) x/=d[i],ans++;
				if(ans>=q[d[i]]){
					tot=1;
					for(j=1;j<=ans-q[d[i]]+1;j++) tot*=d[i];
					pus=min(pus,tot);
				}
				sh-=min(q[d[i]],ans);
			}
		}
		if(sh)printf("%lld\n",now);
		else printf("%lld\n",now/pus);
		q.clear();
	}
}