#include<stdio.h>
#include<algorithm>
using namespace std;
int n,w[310000],i,S[1010000],k,j,t1,t2;
int main()
{
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++){
		scanf("%d",&w[i]);
		S[w[i]]++;
	}
	sort(w,w+n);
	for(i=1;i<=1000000;i++)S[i]+=S[i-1];
	if(w[0]<=k+1){
		printf("%d\n",w[0]);
		return 0;
	}
	for(i=w[0];i>k+1;i--){
		for(j=0;j+k<1000000;j+=i){
			t1=j+k;
			t2=j+i-1;
			if(t2>1000000)t2=1000000;
			if(S[t2]-S[t1])break;
		}
		if(j+k>=1000000)break;
	}
	printf("%d\n",i);
}