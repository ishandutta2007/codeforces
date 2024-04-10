#include<bits/stdc++.h>
#define N 200100
#define M 1001000
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
ll a[N],prm[M];
bool notp[M];
int pcnt;
inline long long gen(){
	return 1LL*rand()*(RAND_MAX+1)+rand();
}
int main(){
	for(int i=2;i<M;i++){
		if(!notp[i]){
			prm[pcnt++]=i;
		}
		for(int j=0;j<pcnt&&i*prm[j]<M;j++){
			notp[i*prm[j]]=true;
			if(i%prm[j]==0) break;
		}
	}
	srand(time(0));
	int n;
	long long ans;
	vector<ll> res;
	scanf("%d",&n);
	ans=n;
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=0;i<100;i++){
		int x1=gen()%n;
		for(int j=-1;j<=1;j++){
			ll tmp=abs(a[x1]+j);
			if(tmp==0) continue;
			for(int k=0;k<pcnt&&prm[k]*prm[k]<=tmp;k++){
				if(tmp%prm[k]==0){
					res.push_back(prm[k]);
				}
				while(tmp%prm[k]==0) tmp/=prm[k];
			}
			if(tmp>1) res.push_back(tmp);
		}
	}
	sort(res.begin(),res.end());
	res.resize(unique(res.begin(),res.end())-res.begin());
	for(int i=0;i<res.size();i++){
		ll p=res[i];
		//printf("%lld\n",p);
		ll tmp=0;
		for(int j=0;j<n;j++){
			tmp+=min(p-a[j]%p,a[j]>=p?a[j]%p:p);
			if(tmp>ans) break;
		}
		if(tmp<ans){
			//printf("%lld %lld\n",p,tmp);
			ans=tmp;
		}
	}
	printf("%lld\n",ans);
	return 0;
}