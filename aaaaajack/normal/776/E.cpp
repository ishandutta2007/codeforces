#include<bits/stdc++.h>
#define N 1001000
#define Q 1000000007
using namespace std;
bool np[N];
int prm[N],pcnt;
int main(){
	for(int i=2;i<N;i++){
		if(!np[i]) prm[pcnt++]=i;
		for(int j=i+i;j<N;j+=i){
			np[j]=true;
		}
	}
	long long n,k;
	scanf("%I64d%I64d",&n,&k);
	k=(k+1)/2;
	while(k>0&&n>1){
		k--;
		long long tmp=n;
		for(int j=0;j<pcnt&&1LL*prm[j]*prm[j]<=tmp;j++){
			if(tmp%prm[j]==0){
				n/=prm[j];
				n*=prm[j]-1;
				while(tmp%prm[j]==0) tmp/=prm[j];
			}
		}
		if(tmp>1){
			n/=tmp;
			n*=tmp-1;
		}
	}
	printf("%I64d\n",n%Q);
	return 0;
}