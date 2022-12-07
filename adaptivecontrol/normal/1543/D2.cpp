#include<bits/stdc++.h>
using namespace std;
int add(int a,int b,int k){
	int c=0,pw=1;
	while(a||b){
		c+=(a+b)%k*pw;
		a/=k;b/=k;
		pw*=k;
	}
	return c;
}
int era(int a,int b,int k){
	int c=0,pw=1;
	while(a||b){
		c+=((a-b)%k+k)%k*pw;
		a/=k;b/=k;
		pw*=k;
	}
	return c;
}
int T,n,k;
int main(){
	cin>>T;
	while(T--){
		cin>>n>>k;
		int sum=0,nw=0,res;
		for(int i=1;i<=n;i++){
			if(i%2)
				nw=add(sum,i-1,k);
			else
				nw=era(sum,i-1,k);
			printf("%d\n",nw);
			fflush(stdout);
			scanf("%d",&res);
			if(res)break;
			sum=era(nw,sum,k);
		}
	}
}