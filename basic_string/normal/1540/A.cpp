
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+3;
int a[N];
void put(__int128 s){
	if(s==0){return;}
	if(s<0)putchar('-'),put(-s);
	else put(s/10),putchar(s%10+'0');
}
int main(){
	int T,n,i;
	__int128 ans=0;
	for(scanf("%d",&T);T--;){
		scanf("%d",&n);
		for(i=1;i<=n;++i)scanf("%d",a+i);
		sort(a+1,a+n+1);
		ans=a[n];
		for(i=1;i<=n;++i)ans-=a[i]*1ll*((i-1)-(n-i));
		if(ans==0)putchar('0');else put(ans);
		putchar(10);
	}
	return 0;
}