#include<bits/stdc++.h>
using namespace std;
int T,l,r,mx;
int count(int x,int bt){
	x++;
	int a=x/(bt<<1),b=x%(bt<<1);
	return a*bt+max(b-bt,0);
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&l,&r),mx=0;
		for(int i=1;i<=r;i<<=1)mx=max(mx,count(r,i)-count(l-1,i));
		printf("%d\n",r-l+1-mx);
	}
	return 0;
}