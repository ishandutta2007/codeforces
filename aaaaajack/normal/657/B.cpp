#include<bits/stdc++.h>
#define N 200100
using namespace std;
int a[N];
int b[N];
int main(){
	int n,k,low=-1,ans=0;
	bool neg=true;
	scanf("%d%d",&n,&k);
	for(int i=0;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n;i++){
		b[i]+=a[i];
		if(b[i]<0) b[i+1]+=(b[i]-1)/2,b[i]&=1;
		else b[i+1]+=b[i]/2,b[i]&=1;
		if(low==-1&&b[i]==1){
			low=i;
		}
	}
	b[n]+=a[n];
	if(low==-1) low=n;
	if(b[n]<0){
		if(low<n){
			b[low]=-1;
			for(int i=low+1;i<n;i++){
				b[i]=-(1-b[i]);
			}
			b[n]++;
		}
		long long t=0;
		for(int i=n;i>=low&&t<=k+k;i--){
			t<<=1;
			t-=b[i];
		}
		while(low>=0&&t<=k+k){
			if(a[low]+t<=k&&(low<n||a[n]+t!=0)) ans++;
			t<<=1;
			low--;
		}
	}
	else{
		long long t=0;
		for(int i=n;i>=low&&t<=k+k;i--){
			t<<=1;
			t+=b[i];
		}
		while(low>=0&&t<=k+k){
			if(a[low]-t>=-k&&(low<n||a[n]-t!=0)) ans++;
			t<<=1;
			low--;
		}
	}
	printf("%d\n",ans);
	return 0;
}