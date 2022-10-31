#include<cstdio>
#include<map>
#include<utility>
#define N 2010
using namespace std;
long long gcd(long long a,long long b){
	if(a<0) a=-a;
	if(b<0) b=-b;
	while(b){
		a%=b,a^=b,b^=a,a^=b;
	}
	return a;
}
long long la[N],lb[N],lc[N];
int main(){
	int n;
	int a,b,c,oc=0;
	long long ans=0,tmp=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%I64d%I64d%I64d",&la[i],&lb[i],&lc[i]);
		if(lc[i]==0) oc++,i--,n--;
	}
	if(oc>=2) ans+=n;
	for(int i=0;i<n;i++){
		map<pair<long long,long long>,int> cnt;
		for(int j=0;j<n;j++){
			if(j==i) continue;
			long long px=lc[i]*lb[j]-lc[j]*lb[i], py=la[i]*lc[j]-la[j]*lc[i], pn=la[i]*lb[j]-la[j]*lb[i];
			long long pf=px*lb[j]-py*la[j],ps=lc[j]*pn;
			if(ps<0){
				pf=-pf,ps=-ps;
			}
			long long g=gcd(pf,ps);
			pf/=g,ps/=g;
			tmp+=(cnt[make_pair(pf,ps)]++);
		}
	}
	printf("%I64d\n",ans+tmp/3);
	return 0;
}