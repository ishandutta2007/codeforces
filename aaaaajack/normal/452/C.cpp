#include<cstdio>
using namespace std;
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	if(m==1) printf("%.8f\n",1.0/n);
	else printf("%.8f\n",1.0/n*((2*n-1)*m-n)/(n*m-1));
	return 0;
}