#include<cstdio>
#include<cmath>
using namespace std;
int t,n,m,k,x,y,z,ans;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		x=sqrt(n);
		if(n==x*x) ans=x*2-2;
		else ans=x+ceil(n*1.0/(x+1))-1;
		printf("%d\n",ans);
	}
}