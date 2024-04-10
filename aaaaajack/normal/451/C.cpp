#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	int t;
	long long n,k,d1,d2,r,x;
	scanf("%d",&t);
	while(t--){
		scanf("%I64d%I64d%I64d%I64d",&n,&k,&d1,&d2);
		bool flag=false;
		if((k-d1-d2)%3==0){
			x=(k-d1-d2)/3;
			if(x>=0){
				r=3*max(d1,d2)-d1-d2;
				if(n-k>=r&&(n-k-r)%3==0) flag=true;
			}
		}
		if((k+d1+d2)%3==0){
			x=(k+d1+d2)/3;
			if(x-d1>=0&&x-d2>=0){
				r=d1+d2;
				if(n-k>=r&&(n-k-r)%3==0) flag=true;
			}
		}
		if((k+d1-d2)>=3*d1&&(k+d1-d2)%3==0){
			r=d1+2*d2;
			if(n-k>=r&&(n-k-r)%3==0) flag=true;
		}
		if((k+d2-d1)>=3*d2&&(k+d2-d1)%3==0){
			r=2*d1+d2;
			if(n-k>=r&&(n-k-r)%3==0) flag=true;
		}
		if(flag) puts("yes");
		else puts("no");
	}
	return 0;
}