#include<bits/stdc++.h>
using namespace std;
const int N=2e5+3;
int a[N];
int main(){
	int n,i,j,u,v,s=0;
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",a+i);
	for(i=1;i<=n;++i){
		u=0,v=1<<__lg(a[i])+1;
		for(j=i+2;j<=n;++j){
			u+=a[j-1];
			if(u>=v)break;
			if(u==(a[i]^a[j])&&a[i]>=a[j])++s;
		}
	}
	for(i=n;i;--i){
		u=0,v=1<<__lg(a[i])+1;
		for(j=i-2;j>0;--j){
			u+=a[j+1];
			if(u>=v)break;
			if(u==(a[i]^a[j])&&a[i]>a[j])++s;
		}
	}
	printf("%d",s);
	return 0;
}