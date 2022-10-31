#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	int a[10],mi=-1;
	scanf("%d",&n);
	int cnt[10]={};
	for(int i=1;i<=9;i++){
		scanf("%d",&a[i]);
		if(mi<0||a[i]<mi) mi=a[i];
	}
	for(int i=1;i<=9;i++){
		cnt[i]=n/a[i];
	}
	int mx=0;
	for(int i=9;i>=1;i--){
		if(cnt[i]>mx) mx=cnt[i];
	}
	if(mx==0) puts("-1");
	else{
		while(mx>0){
			for(int i=9;i>=1;i--){
				if(n-a[i]>=(mx-1)*mi){
					printf("%d",i);
					n-=a[i];
					break;
				}
			}
			mx--;
		}
	}
	return 0;
}