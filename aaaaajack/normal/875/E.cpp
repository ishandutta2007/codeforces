#include<bits/stdc++.h>
#define N 100100
using namespace std;
int a[N];
int main(){
	int n,s1,s2;
	scanf("%d%d%d",&n,&s1,&s2);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int l=abs(s1-s2)-1,r=1e9+100;
	while(l+1<r){
		int m=(l+r)/2;
		int lst=n,mx=a[n],mn=a[n];
		for(int i=n-1;i>=1;i--){
			if(mx-a[i]<=m && a[i]-mn<=m){
				lst=i;
				mx=a[i];
				mn=a[i];
			}
			else{
				mx=max(mx,a[i]);
				mn=min(mn,a[i]);
			}
		}
		if(mx-s1<=m && s1-mn<=m || mx-s2<=m && s2-mn<=m){
			r=m;
		}
		else l=m;
	}
	printf("%d\n",r);
	return 0;
}