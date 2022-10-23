#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
int T;
ll n;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%I64d",&n);
		ll x=1,y=n;
		while(y%2==0)y>>=1,x<<=1;
		swap(x,y);
		if(x==1)printf("-1\n");
		else if(x<y*2)printf("%I64d\n",x);
		else printf("%I64d\n",y*2);
	}
    return 0;
}