#include<cstdio>
#include<cstring>
using namespace std;
long long n,m,k,x,y,z,flag;
int main(){
	register int i;
	scanf("%lld%lld",&x,&y);
		if(y>1000) printf("No\n");
		else{
			flag=0;
		    for(i=1;i<=y;i++){
		    	if(x%i!=i-1){flag=1;break;}
		    }
	    	if(flag) printf("No\n");
	    	else printf("Yes\n");
		}
}