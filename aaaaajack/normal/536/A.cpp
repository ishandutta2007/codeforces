#include<cstdio>
using namespace std;
int main(){
	int a,b,n,l,t,m,s,r;
	scanf("%d%d%d",&a,&b,&n);
	while(n--){
		scanf("%d%d%d",&l,&t,&m);
		if(a+1LL*(l-1)*b>t){
			printf("-1\n");
		}
		else{
			s=1<<20;
			r=l;
			while(s){
				if(a+1LL*(r+s-1)*b<=t&&(a+1LL*(l-1)*b+a+1LL*(r+s-1)*b)*(r-l+s+1)/2<=1LL*m*t){
					r+=s;
				}
				s>>=1;
			}
			printf("%d\n",r);
		}
	}
	return 0;
}