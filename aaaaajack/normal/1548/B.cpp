#include<bits/stdc++.h>
#define N 200100
using namespace std;
long long a[N];
long long spt[20][N];
long long gcd(long long x,long long y){
	if(x==0 && y==0) return 0;
	while(y){
		x%=y;
		swap(x,y);
	}
	return x;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++) scanf("%lld",&a[i]);
		for(int i=n-1;i>0;i--){
			a[i]=abs(a[i]-a[i-1]);
			spt[0][i]=a[i];
		}
		for(int j=1;j<20;j++){
			for(int i=1;i+(1<<j)<=n;i++){
				spt[j][i]=gcd(spt[j-1][i],spt[j-1][i+(1<<j-1)]);
			}
		}
		int l=0,r=n;
		while(l+1<r){
			int m=(l+r)/2;
			int s=0;
			while((1<<s+1)<=m) s++;
			bool flag=false;
			for(int i=1;i+m<=n;i++){
				if(gcd(spt[s][i],spt[s][i+m-(1<<s)])!=1){
					flag=true;
					break;
				}
			}
			if(flag) l=m;
			else r=m;
		}
		printf("%d\n",1+l);
	}
	return 0;
}