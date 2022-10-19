#include<bits/stdc++.h>
using namespace std;
#define int long long
int T,a,b,c,d;
signed main(){
	scanf("%I64d",&T);
	while(T--){
		scanf("%I64d%I64d%I64d%I64d",&a,&b,&c,&d);
		a-=b;
		if(a<=0){printf("%I64d\n",b);continue;}
		if(c<=d){puts("-1");continue;}
		d=c-d;
		if(a%d)d=a/d+1;
		else d=a/d;
		printf("%I64d\n",1ll*c*d+b);
	}
	return 0;
}