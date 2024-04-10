#include<bits/stdc++.h>
using namespace std;
int wk(int a,int n,int p){
	int b=p%a,m=(n-p/a+1ll)*a/p;
	return b*1ll*m<a?max(b,a-b*m):wk(b,m,a);
}
int main(){
	int T,a,n,p,h;
	for(scanf("%d",&T);T--;)scanf("%d%d%d%d",&a,&n,&p,&h),a%=p,puts((a*1ll*n<p?a:wk(a,n,p))>h?"NO":"YES");
	return 0;
}