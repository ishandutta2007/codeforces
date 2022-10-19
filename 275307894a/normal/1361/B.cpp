#include<cstdio>
#include<algorithm>
#define mod 1000000007
using namespace std;
int n,m,k,x,y,z,flag,t;
long long p,f[1000039],ans1,ans2,now,tot,nows,s[1000039];
inline long long mpow(long long x,int y){
	long long ans=1;
	while(y){
		if(y&1) ans=ans*x%mod;
		y>>=1;x=x*x%mod;
	}
	return ans;
}
int main(){
//	freopen("1.in","r",stdin);
	register int i,j,h;
	scanf("%d",&t);
	while(t--){
		scanf("%d%lld",&n,&p);
		tot=1;
		for(i=1;i&&p!=1;i++){
			tot*=p;
			if(tot>=n){tot=i;break;}
		}
		for(i=1;i<=n;i++) scanf("%lld",&f[i]);
		sort(f+1,f+n+1);
		if(p==1) {printf("%d\n",n%2);continue;}
		for(i=1;i<=n;i++) s[f[i]]++;
		ans1=ans2=0;
		for(i=n;i>=1;i--){
			nows=i;i=f[i];
			if(s[i]%2==0) ans1+=mpow(p,i)*s[i]/2%mod,ans2+=mpow(p,i)*s[i]/2%mod,s[i]=0;
			else{
				ans1+=mpow(p,i)*(s[i]/2+1)%mod;ans2+=mpow(p,i)*(s[i]/2)%mod;s[i]=0;
				ans1%=mod;ans2%=mod;
				now=1;flag=0;
				for(j=nows-1;j>=1;j--){
					if(!s[f[j]]) continue;
					if(f[j+1]-f[j]>=tot) break;
					now*=mpow(p,f[j+1]-f[j]);
					if(now>=n) break;
					if(s[f[j]]>=now){
						s[f[j]]-=now;
						ans2+=now*mpow(p,f[j])%mod;
						flag=1;
						break;
					}
					now-=s[f[j]];
					ans2+=s[f[j]]*mpow(p,f[j])%mod;
					s[f[j]]=0;
				}
				if(!flag){
					for(h=j;h>=1;h--){
						ans2+=s[f[h]]*mpow(p,f[h])%mod;
						s[f[h]]=0;
					}
					break;
				} 
				else nows=j+1;
			}
			ans1%=mod;ans2%=mod;
			i=nows;
		}
		ans1%=mod;ans2%=mod;
		printf("%lld\n",(ans1-ans2+mod)%mod);
		for(i=1;i<=n;i++) s[f[i]]=0;
	}
}