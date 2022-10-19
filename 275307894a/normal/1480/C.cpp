#include<cstdio>
using namespace std;
int n,m,k,x,y,z,l,r,mid;
int main(){
	register int i;
	scanf("%d",&n);
	printf("? 1\n");fflush(stdout);
	scanf("%d",&x);
	if(n==1){printf("! %d\n",1);fflush(stdout);return 0;}
	printf("? 2\n");fflush(stdout);scanf("%d",&y);
	if(x<y){printf("! %d\n",1);fflush(stdout);return 0;}
	l=1;
	printf("? %d\n",n);fflush(stdout);
	scanf("%d",&x);
	printf("? %d\n",n-1);fflush(stdout);
	scanf("%d",&y);
	if(x<y){printf("! %d\n",n);fflush(stdout);return 0;}
	r=n;
	while(l+1<r){
		mid=l+r>>1;
		printf("? %d\n",mid);fflush(stdout);scanf("%d",&x);
		printf("? %d\n",mid-1);fflush(stdout);scanf("%d",&y);
		printf("? %d\n",mid+1);fflush(stdout);scanf("%d",&z);
		if(x<y&&x<z){printf("! %d\n",mid);fflush(stdout);return 0;}
		if(y>x&&x>z) l=mid;
		else r=mid;
	}
}