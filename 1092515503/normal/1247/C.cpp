#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
bool che(int tot){
	if(n-m*tot<0)return false;
	return __builtin_popcount(n-m*tot)<=tot&&n-m*tot>=tot;
}
signed main(){
	scanf("%I64d%I64d",&n,&m);
	for(int i=1;i<=100000;i++)if(che(i)){printf("%I64d\n",i);return 0;}
	puts("-1");
	return 0;
}