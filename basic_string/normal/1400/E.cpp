#include<bits/stdc++.h>
using namespace std;
int a[5009];
int get(int l,int r){
	if(l>r)return 0;
	int i,j,w=2e9;
	for(i=l;i<=r;++i)if(a[i]<w)j=i,w=a[i];
	for(i=l;i<=r;++i)a[i]-=w;
	return min(r-l+1,w+get(l,j-1)+get(j+1,r));
}
int main(){
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",a+i);
	printf("%d",get(1,n));
	return 0;
}