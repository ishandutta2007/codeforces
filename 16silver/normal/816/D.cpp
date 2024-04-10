#include <stdio.h>
long long s[100001];
long long b[100001];
long long a[200000];
#define P 1000000007
int p(long long n, long long k){
	if(k == 0) return 1;
	long long h = p(n, k >> 1);
	if (k & 1) return (((h*h) % P)*n) % P;
	else return (h*h) % P;
}
int main(){
    long long n,i,r=0;
    s[0] = 1;
    scanf("%I64d",&n);
    for(i=0;i<n;i++) scanf("%I64d",&(a[i]));
	for(i=1;i<100001;i++) s[i]=(s[i-1]*i)%P;
	if(n%4==0){
	    for(i=0;i<n/2;i++){
	        b[i]=(s[n/2-1]*(p((s[i]*s[n/2-1-i])%P,P-2)))%P;
	    }
	    for(i=0;i<n;i++){
	        if(i%2==0) r=(r+b[i/2]*a[i])%P;
	        else r=(r+(P-b[i/2])*a[i])%P;
	    }
	}
	else if(n%4==1){
	    for(i=0;i<=n/2;i++){
	        b[i]=(s[n/2]*(p((s[i]*s[n/2-i])%P,P-2)))%P;
	    }
	    for(i=0;i<n;i++){
	        if(i%2==0) r=(r+b[i/2]*a[i])%P;
	    }
	}
	else if(n%4==2){
	    for(i=0;i<n/2;i++){
	        b[i]=(s[n/2-1]*(p((s[i]*s[n/2-1-i])%P,P-2)))%P;
	    }
	    for(i=0;i<n;i++){
	        r=(r+b[i/2]*a[i])%P;
	    }
	}
	else{
	    for(i=0;i<n/2;i++){
	        b[i]=(s[n/2-1]*(p((s[i]*s[n/2-1-i])%P,P-2)))%P;
	    }
	    for(i=0;i<n;i++){
	        if(i%2==1) r=(r+((2*b[i/2])%P)*a[i])%P;
	        else{
	            if(i==0) r=(r+a[i])%P;
	            else if(i==n-1) r=(r+(P-1)*a[i])%P;
	            else r=(r+(P+b[i/2]-b[i/2-1])*a[i])%P;
	        }
	    }
	}
	printf("%I64d",r);
}