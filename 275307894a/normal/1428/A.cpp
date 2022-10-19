#include<cstdio>
#include<cmath>
using namespace std;
int n,m,k,x,y,z,t,a[139],ans;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d%d",&n,&m,&x,&y);
		ans=0;
		ans+=abs(n-x);
		ans+=abs(y-m);
		if(n!=x&&y!=m) ans+=2;
		printf("%d\n",ans);
	}
}