#include<cstdio>
#include<cmath>
using namespace std;
long long n,m,k,x,y,z,t;
int main(){
	scanf("%lld",&t);
	while(t--){
		scanf("%lld%lld",&n,&m);
		k=sqrt(n*n/2);
		k=k/m*m;
		printf("%s\n",k*k+(k+m)*(k+m)<=n*n?"Ashish":"Utkarsh");
	}
}