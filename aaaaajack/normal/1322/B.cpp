#include<bits/stdc++.h>
#define N 400100
using namespace std;
int a[N],b[N],cnt[2];
int main(){
	int n,msk=1,ans=0;
	long long pre=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	while(msk<=4e7){
		if(pre&1) ans^=msk;
		pre=0;
		int f=0;
		cnt[0]=cnt[1]=0;
		for(int i=0;i<n;i++){
			if(a[i]&msk) cnt[1]++;
			else cnt[0]++;
		}
		cnt[1]+=cnt[0];
		for(int i=n-1;i>=0;i--){
			if(a[i]&msk) b[--cnt[1]]=a[i];
			else b[--cnt[0]]=a[i];
		}
		for(int i=0;i<n;i++) a[i]=b[i];
		int r=n-1,msk_a=msk+msk-1;
		for(int i=0;i<n;i++){
			while(r>=0&&(a[r]&msk_a)+(a[i]&msk_a)>msk_a){
				r--;
			}
			if(n%2==0) ans^=(a[i]&msk);
			pre+=(n-1-r);
			if(a[i]&msk) pre--;
		}
		assert(pre%2==0);
		pre/=2;
		msk<<=1;
	}
	printf("%d\n",ans);
	return 0;
}