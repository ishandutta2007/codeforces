#include<bits/stdc++.h>
using namespace std;
int a[100005];
char tt[7],op[100005];
long long dp[100005];
int p[100005];
void solve(int l,int r){
	if(l>=r)return;
	int lim=20*(r-l+1);
	long long cj=1;
	for(int i=l;i<=r;++i)cj=min(1ll+lim,cj*a[i]);
	if(cj>lim){
		while(l<=r&&a[l]==1){
			op[l]='+';
			++l;
		}
		while(l<=r&&a[r]==1){
			op[r-1]='+';
			--r;
		}
		if(l<=r){
			for(int i=l;i<r;++i)op[i]='*';
		}
		return;
	}
	dp[l-1]=0;
	for(int i=l;i<=r;++i){
		dp[i]=dp[i-1]+a[i];
		p[i]=i-1;
		if(a[i]==1)continue;
		long long ans=a[i];
		for(int j=i-1;j>=l;--j){
			ans*=a[j];
			if(dp[i]<ans+dp[j-1]){
				dp[i]=ans+dp[j-1];
				p[i]=j-1;
			}
		}
	}
	int wz=r;
	while(wz>=l){
		for(int i=p[wz]+1;i<wz;++i)op[i]='*';
		wz=p[wz];
		if(wz>=l)op[wz]='+';
	}
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	scanf("%s",tt+1);
	int aa=strlen(tt+1);
	if(aa==1){
		for(int i=1;i<n;++i)printf("%d%c",a[i],tt[1]);
		printf("%d\n",a[n]);
		return 0;
	}
	if(aa==2){
		if(tt[1]*tt[2]=='+'*'-'){
			for(int i=1;i<n;++i)printf("%d+",a[i]);
			printf("%d\n",a[n]);
			return 0;
		}else if(tt[1]*tt[2]=='-'*'*'){
			int wz=n+1;
			for(int i=n;i>=1;--i)if(a[i]==0)wz=i;
			if(wz==1||wz==n+1){
				for(int i=1;i<n;++i)printf("%d*",a[i]);
				printf("%d\n",a[n]);
			}else{
				for(int i=1;i<n;++i){
					if(i==wz-1)printf("%d-",a[i]);
					else printf("%d*",a[i]);
				}
				printf("%d\n",a[n]);
			}
			return 0;
		}
	}
	int lst=0;
	for(int i=1;i<=n;++i)if(a[i]==0){
		solve(lst+1,i-1);
		op[i-1]=op[i]='+';
		lst=i;
	}
	solve(lst+1,n);
	for(int i=1;i<n;++i)printf("%d%c",a[i],op[i]);
	printf("%d\n",a[n]);
	return 0;
}