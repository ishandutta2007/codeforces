#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,q,t,x,a[2]={0,1};
	scanf("%d%d",&n,&q);
	while(q--){
		scanf("%d",&t);
		if(t==1){
			scanf("%d",&x);
			if(x&1){
				int tmp[2]={(a[1]+n+n-(x+1))%n,(a[0]+n-(x-1))%n};
				a[0]=tmp[0],a[1]=tmp[1];
			}
			else{
				a[0]=(a[0]+n-x)%n;
				a[1]=(a[1]+n-x)%n;
			}
		}
		else{
			swap(a[0],a[1]);
		}
	}
	for(int i=0;i<n;i++){
		printf("%d ",(a[i&1]+(i^(i&1)))%n+1);
	}
	return 0;
}