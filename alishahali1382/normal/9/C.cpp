#include <bits/stdc++.h>
int n,tmp,A[512],i,j;
int main(){
	while(i++<512){
		tmp=i+1;
		for (j=1;tmp;tmp/=2,j*=10)A[i]+=j*(tmp%2);
	}
	scanf("%d",&n);
	printf("%d\n",std::upper_bound(A, A+512, n)-A);
}