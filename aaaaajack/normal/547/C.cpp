#include<cstdio>
#define N 500100
using namespace std;
int cnt[N],lpf[N],prm[N],a[N],sign[N],pcnt;
bool nprm[N],in[N];
int main(){
	int n,q,i,j,k,x,ad,vp[20],v[300],psz,sz,num=0;
	long long tmp,now=0;
	for(i=2;i<N;i++){
		if(!nprm[i]){
			prm[pcnt++]=i;
			lpf[i]=i;
			sign[i]=1;
		}
		for(j=0;j<pcnt&&prm[j]*i<N;j++){
			nprm[i*prm[j]]=true;
			lpf[i*prm[j]]=prm[j];
			k=i;
			while(k%prm[j]==0) k/=prm[j];
			sign[i*prm[j]]=-sign[k];
			if(i%prm[j]==0){
				
				break;
			}
		}
	}
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	while(q--){
		scanf("%d",&x);
		psz=0;
		for(i=a[x];i>1;psz++){
			vp[psz]=lpf[i];
			while(i%vp[psz]==0) i/=vp[psz];
		}
		sz=1;
		v[0]=1;
		tmp=0;
		for(i=0;i<psz;i++){
			for(j=0;j<sz;j++){
				v[j+sz]=v[j]*vp[i];
				if(in[x]){
					cnt[v[j+sz]]--;
					tmp+=sign[v[j+sz]]*cnt[v[j+sz]];
				}
				else{
					tmp+=sign[v[j+sz]]*cnt[v[j+sz]];
					cnt[v[j+sz]]++;
				}
			}
			sz<<=1;
		}
		if(in[x]){
			num--;
			in[x]=0;
			now-=(num-tmp);
		}
		else{
			in[x]=1;
			now+=(num-tmp);
			num++;
		}
		printf("%I64d\n",now);
	}
	return 0;
}