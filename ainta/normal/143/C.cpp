#include<stdio.h>
#include<algorithm>
using namespace std;
int n;
int w[100001],i,j,c;
__int64 p[100001],x,a=-1,b,nn;
int main(){
	scanf("%d",&n);
	for(i=1;i*i<=n;i++){
		if(n%i==0){
			if(i*i==n)w[c++]=i;
			else w[c++]=i,w[c++]=n/i;
		}
	}
	nn=n;
	stable_sort(w,w+c);
	for(i=0;i<c;i++)p[i]=w[i];
	for(i=0;i<c;i++){
		if(p[i]*p[i]*p[i]>n)break;
		for(j=i;j<c;j++){
			if(p[i]*p[j]*p[j]>n)break;
			if(n%(p[i]*p[j])==0){
				x=n/p[i]/p[j];
				if((x+2)*(p[j]+2)*(p[i]+1)<a||a==-1)a=(x+2)*(p[j]+2)*(p[i]+1);
				if((x+2)*(p[j]+1)*(p[i]+2)<a||a==-1)a=(x+2)*(p[j]+1)*(p[i]+2);
				if((x+1)*(p[j]+2)*(p[i]+2)<a||a==-1)a=(x+1)*(p[j]+2)*(p[i]+2);
				if((x+2)*(p[j]+2)*(p[i]+1)>b)b=(x+2)*(p[j]+2)*(p[i]+1);
				if((x+2)*(p[j]+1)*(p[i]+2)>b)b=(x+2)*(p[j]+1)*(p[i]+2);
				if((x+1)*(p[j]+2)*(p[i]+2)>b)b=(x+1)*(p[j]+2)*(p[i]+2);
			}
		}
	}
	printf("%I64d %I64d\n",a-n,b-n);
}