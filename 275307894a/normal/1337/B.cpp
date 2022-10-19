#include<cstdio>
using namespace std;
int n,m,k,x,y,z,t;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&x,&y,&z);
		while(y&&x>20) x=x/2+10,y--;
		while(z&&x>0) x-=10,z--;
		if(x>0) printf("NO\n");
		else printf("YES\n");
	}
}