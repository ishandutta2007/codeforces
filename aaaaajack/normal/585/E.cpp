#include<cstdio>
#include<vector>
#include<algorithm>
#define N 10001000
#define M 500100
#define Q 1000000007
using namespace std;
int mob[N],cnt[N];
int lpf[N];
int prm[N/10],pcnt;
int a[M];
int qp[N];
int main(){
	qp[0]=1;
	qp[1]=2;
	for(int i=2;i<N;i++){
		qp[i]=(qp[i-1]<<1)%Q;
		if(!lpf[i]) lpf[i]=i,prm[pcnt++]=i;
		for(int j=0;j<pcnt&&i*prm[j]<N;j++){
			lpf[i*prm[j]]=prm[j];
			if(i%prm[j]==0) break;
		}
	}
	vector<int> v;
	int n;
	long long ans=0;
	mob[1]=-1;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		v.assign(1,1);
		cnt[1]++;
		for(int tmp=a[i];tmp>1;){
			int p=lpf[tmp],tsz=v.size();
			while(tmp%p==0) tmp/=p;
			for(int i=0;i<tsz;i++){
				v.push_back(v[i]*p);
				mob[v[i]*p]=-mob[v[i]];
				cnt[v[i]*p]++;
			}
		}
	}
	for(int i=2;i<N;i++){
		ans+=1LL*mob[i]*(qp[cnt[i]]-1)*(n-cnt[i])%Q;
	}
	ans%=Q;
	if(ans<0) ans+=Q;
	printf("%d\n",(int)ans);
	return 0;
}