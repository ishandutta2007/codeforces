#include<cstdio>
#include<vector>
#define S 1000000
using namespace std;
bool x[S+1000]={0},y[S+1000]={0};
int main(){
	int m,n,t,i;
	scanf("%d",&n);
	m=n;
	for(i=0;i<n;i++){
		scanf("%d",&t);
		x[t]=true;
	}
	for(i=1;i<=S;i++){
		if(x[i]&&!x[S+1-i]) y[S+1-i]=true,n--;
	}
	for(i=1;i<=S&&n;i++){
		if(!x[i]&&!x[S+1-i]) y[i]=y[S+1-i]=true,n-=2;
	}
	printf("%d\n",m);
	for(i=1;i<=S;i++){
		if(y[i]){
			printf("%d",i);
			if(m--) putchar(' ');
			else putchar('\n');
		}
	}
	return 0;
}