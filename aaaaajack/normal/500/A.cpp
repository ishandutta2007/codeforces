#include<cstdio>
#define N 30100
using namespace std;
bool r[N];
int main(){
	int n,i,x,t;
	r[0]=true;
	scanf("%d%d",&n,&t);
	for(i=0;i<n-1;i++){
		scanf("%d",&x);
		if(r[i]) r[i+x]=true;
	}
	if(r[t-1]) puts("YES");
	else puts("NO");
	return 0;
}