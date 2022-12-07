#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;
typedef long long ll;
ll n,k,num,K,lef,rig=-1;
int a[70+100005];//a[100005] means 2^0.
int main(){
	scanf("%I64d%I64d",&n,&k);
	while(n!=0){
		num++;
		if(n&1){
			if(rig==-1) rig = num+100004;
			
			a[num+100004] = 1;
			K++;
		}
		n >>= 1;
		if(n==0) lef = num+100004;
	}
	if(K > k) printf("No\n");
	else{
		printf("Yes\n");
		while(K<k){
			if(k-K>=a[lef]){
				a[lef]--;
				a[lef-1]+=2;
			}else{
				a[rig]--;
				a[rig-1]+=2;
			}
			if(a[lef]==0) lef--;
			if(a[rig-1]>0) rig--;
			K++;
		}
		for(int i=lef;i>=rig;i--){
			for(int j=a[i];j>=1;j--){
				printf("%d",i-100005);
				if(i==rig&&j==1) printf("\n");
				else printf(" ");
			}
		}
	}
	
	return 0;
}