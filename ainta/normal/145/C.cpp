#include<stdio.h>
int n,k,i,w[100001],c[2100],ct;
__int64 C[100001],Mod=1000000007,t,s,D[2100],R;
int main()
{
	int a,b,d,e,j;
	scanf("%d%d",&n,&k);
	C[0]=1;
	for(i=1;i<=n;i++){
		scanf("%d",&w[i]);
		a=w[i];d=e=0;
		while(a){
			e*=2;
			d++;
			b=a%10;
			if(b==4)e++;
			else if(b!=7)break;
			a/=10;
		}
		if(!a)c[(1<<d)+e]++,ct++;
	}
	n-=ct;
	for(i=1;i<=k&&i<=n;i++){
		t=i,a=1000000005,s=1;
		while(a){
			if(a&1){
				s*=t;
				s%=Mod;
			}
			t=(t*t)%Mod;
			a/=2;
		}
		C[i]=C[i-1]*s%Mod;
		C[i]=C[i]*(__int64)(n+1-i)%Mod;
	}
	a=0;D[0]=1;
	for(i=2;i<=2047;i++){
		if(!c[i])continue;
		for(j=a;j>=0;j--){
			D[j+1]+=D[j]*(__int64)c[i];
			D[j+1]%=Mod;
		}
		a++;
	}
	for(i=0;i<=a&&i<=k;i++){
		R+=C[k-i]*D[i];
		R%=Mod;
	}
	printf("%I64d\n",R);
}