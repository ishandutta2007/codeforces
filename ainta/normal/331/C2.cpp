#include<stdio.h>
int D[10][1000001],p[10][1000001];
long long Res;
int main()
{
	long long i,t,j,k,r;
	for(j=0;j<10;j++){
		D[j][0]=0;
		for(i=1;i<1000000;i++){
			D[j][i]=999999999;
			t=i;
			k=j;
			while(t){
				if(k<t%10)k=t%10;
				t/=10;
			}
			if(k>i){
				k=i;
				D[j][i]=1;
				p[j][i]=i;
			}
			else D[j][i]=D[j][i-k]+1,p[j][i]=p[j][i-k];
		}
	}
	long long n;
	scanf("%lld",&n);
	r=n%1000000LL;
	for(i=n/1000000LL;i>=0;i--){
		t=i;
		k=0;
		while(t){
			if(k<t%10)k=t%10;
			t/=10;
		}
		Res=Res+(long long)D[k][r];
		if(p[k][r]==0){
			if(i!=0){
				Res=Res+1LL;
				r=1000000-k;
			}
		}
		else{
			r=1000000+p[k][r]-k;
		}
	}
	printf("%lld\n",Res);
}