#include<stdio.h>
int n,i,D[5001],j,R;
__int64 w[5001],o[5001],po[5001],t;
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%I64d",&w[i]);
		t=w[i];
		while((t%2LL) == 0){
			t/=2LL;
			po[i]++;
		}
		o[i]=t;
	}
	for(i=n;i>=1;i--){
		D[i]=1;
		for(j=i+1;j<=n;j++){
			if(D[i]<=D[j] && o[i]%o[j]==0 && (po[j]==po[i]+j-i || po[j]<j-i)){
				D[i]=D[j]+1;
			}
		}
	}
	for(i=1;i<=n;i++){
		if(R<D[i])R=D[i];
	}
	printf("%d\n",n-R);
}