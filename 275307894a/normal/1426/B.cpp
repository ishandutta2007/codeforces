#include<cstdio>
using namespace std;
int n,m,k,x,y,z,sx,sy,t,flag;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		flag=0;
		while(n--){
			scanf("%d%d%d%d",&x,&y,&sx,&sy);
			if(y==sx) flag=1;
		} 
		if(flag&&m%2==0) printf("YES\n");
		else printf("NO\n");
	}
}