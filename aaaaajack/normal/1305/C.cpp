#include<bits/stdc++.h>
#define N 200100
using namespace std;
int cnt[1010],a[N];
long long sum[1010];
int ap(int a,long long p,int m){
	int r=1;
	while(p){
		if(p&1) r=r*a%m;
		p>>=1;
		a=a*a%m;
	}
	return r;
}
int main(){
	int n,m,ans=1,pre=0;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	sort(a,a+n);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			sum[(a[i]+m-j)%m]+=cnt[j];
		}
		cnt[a[i]%m]++;
	}
	for(int i=0;i<m;i++){
		//if(sum[i]) printf("%d %d\n",i,sum[i]);
		ans*=ap(i,sum[i],m);
		ans%=m;
	}
	printf("%d\n",ans);
	return 0;
}