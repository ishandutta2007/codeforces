#include<bits/stdc++.h>
using namespace std;
int T,n;
long long m,a[2][200100];
bool func(int id){
	long long mx=0x8080808080808080;
	for(int i=1;i<=n;i++)mx=max(mx,a[id][i]);
	bool same=true;
	for(int i=1;i<=n;i++)same&=(a[id^1][i]==mx-a[id][i]),a[id^1][i]=mx-a[id][i];
	return same;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%I64d",&n,&m);
		for(int i=1;i<=n;i++)a[0][i]=a[1][i]=0x3f3f3f3f3f3f3f3f;
		for(int i=1;i<=n;i++)scanf("%I64d",&a[0][i]);
		func(0);
		for(int i=1;i<m;i++)if(func(i&1))break;
		for(int i=1;i<=n;i++)printf("%I64d ",a[m&1][i]);puts("");
	}
	return 0;
}