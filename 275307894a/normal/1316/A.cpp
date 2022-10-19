#include<cstdio>
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
int n,m,t,ans,tot,pus,x;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		ans=0;
		while(n--) scanf("%d",&x),ans+=x;
		printf("%d\n",min(m,ans));
	}
	return 0;
}