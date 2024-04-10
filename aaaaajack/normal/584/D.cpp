#include<cstdio>
#include<cstdlib>
#define N 2000000
using namespace std;
int qp(int x,int p,int q){
	int r=1;
	while(p){
		if(p&1) r=1LL*r*x%q;
		x=1LL*x*x%q;
		p>>=1;
	}
	return r;
}
int gcd(int a,int b){
	while(b){
		a%=b;
		a^=b,b^=a,a^=b;
	}
	return a;
}
bool prime_test(int x){
	for(int t=0;t<20;t++){
		int y=x-1,s=0,a=rand()%x;
		if(a==0) continue;
		if(gcd(a,x)>1) return false;
		while(y%2==0){
			y>>=1;
			s++;
		}
		bool flag=false;
		int tmp=qp(a,y,x);
		if(tmp==1) flag=true;
		else{
			for(int i=0;i<s;i++){
				if(tmp==x-1){
					flag=true;
					break;
				}
				tmp=1LL*tmp*tmp%x;
			}
		}
		if(!flag){
			return false;
		}
	}
	return true;
}
int prm[N],pcnt;
bool isprm[N];
int main(){
	int n;
	for(int i=2;i<N;i++) isprm[i]=true;
	for(int i=2;i<N;i++){
		if(isprm[i]) prm[pcnt++]=i;
		for(int j=0;j<pcnt&&i*prm[j]<N;j++){
			isprm[i*prm[j]]=false;
			if(i%prm[j]==0) break;
		}
	}
	scanf("%d",&n);
	if(prime_test(n)){
		printf("%d\n%d\n",1,n);
	}
	else{
		int x;
		for(x=n-2;x>=1;x-=2){
			if(prime_test(x)) break;
		}
		if(x==n-2){
			printf("2\n%d %d\n",2,x);
		}
		else{
			for(int j=0;j<pcnt;j++){
				if(isprm[n-x-prm[j]]){
					printf("3\n%d %d %d\n",x,prm[j],n-x-prm[j]);
					break;
				}
			}
		}
	}
	return 0;
}