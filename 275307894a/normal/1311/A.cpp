#include<cstdio>
using namespace std;
int t,a,b;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&a,&b);
		if(a==b) printf("0\n");
		else if((a>b&&(a-b)%2==0)||(a<b&&(b-a)%2==1)) printf("1\n");
		else printf("2\n");
	}
}