#include<cstdio>
using namespace std;
int n,m,k,x,y,z,t;
inline void swap(int &x,int &y){x^=y^=x^=y;}
int main(){
	register int i;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);
		if(n>k){
			if(n%k)printf("2\n");
			else printf("1\n");
		} 
		else if(k%n==0) printf("%d\n",k/n);
		else printf("%d\n",k/n+1);
	}
}