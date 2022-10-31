#include<bits/stdc++.h>
#define N 300100
#define Q 998244353
using namespace std;
long long a[N];
int d[N],odd[N];
int s0[N],s1[N];
int count(long long x){
	int r=0;
	while(x){
		r++;
		x-=x&-x;
	}
	return r;
}
int main(){
	int n;
	long long ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		d[i]=count(a[i]);
		odd[i]=d[i]&1;
		odd[i]^=odd[i-1];
		s0[i]=s0[i-1];
		s1[i]=s1[i-1];
		if(odd[i]) s1[i]++;
		else s0[i]++;
	}
	for(int i=1;i<=n;i++){
		if(odd[i-1]) ans+=s1[n]-s1[i-1];
		else ans+=s0[n]-s0[i-1];
		int pre=0,mx=0;
		for(int j=i;j<=min(i+60,n);j++){
			pre+=d[j];
			mx=max(mx,d[j]);
			if(odd[j]==odd[i-1] && mx+mx>pre) ans--; 
		}
	}
	printf("%lld\n",ans);
	return 0;
}