#include<cstdio>
using namespace std;
int c[50];
int main(){
	long long s,t,d;
	long long ans=1;
	long long sm=0;
	scanf("%I64d%I64d",&s,&t);
	if(s==t) sm=2;
	if(s<t) ans=0;
	else{
		d=s-t;
		if(d&1) ans=0;
		else{
			d>>=1;
			if(d&t) ans=0;
			else{
				while(t){
					if(t&1) ans<<=1;
					t>>=1;
				}
			}
		}
	}
	printf("%I64d\n",ans-sm);
	return 0;
}