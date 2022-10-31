#include<cstdio>
using namespace std;
int main(){
	int n,k,i,l,r;
	scanf("%d%d",&n,&k);
	l=1,r=n;
	for(i=0;i<k;i++){
		if(i) putchar(' ');
		if(i&1) printf("%d",r--);
		else printf("%d",l++);
	}
	if(k&1) for(i=l;i<=r;i++) printf(" %d",i);
	else for(i=r;i>=l;i--) printf(" %d",i);
	putchar('\n');
	return 0;
}