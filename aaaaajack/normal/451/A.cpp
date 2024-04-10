#include<cstdio>
using namespace std;
int main(){
	int m,n,t;
	scanf("%d%d",&m,&n);
	if(m<n) t=m;
	else t=n;
	if(t&1) puts("Akshat");
	else puts("Malvika");
	return 0;
}