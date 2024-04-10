#include<cstdio>
#include<cmath>
using namespace std;
long long n,m,k,x,y,z,t,flag,now;
int main(){
	register int i;
	scanf("%lld",&t);
	while(t--){
		scanf("%lld%lld",&n,&m);
		x=0;flag=0;
		if(n<m){
			now=n;
			while(n<=m){
				if(n==m){flag=1;break;}
				n*=2;
				if(n==m){flag=1;break;}
			}
			if(flag)  printf("%d\n",(int)(log2(m/now)+2)/3);
			else printf("-1\n");
		}
		else if(n==m) printf("0\n");
		else if(n>m){
			now=n;
			while(n%2==0){
				if(n==m){flag=1;break;}
				n/=2;
				if(n==m){flag=1;break;}
			}
			if(flag) printf("%d\n",(int)(log2(now/m)+2)/3);
			else printf("-1\n");
		}
	}
}