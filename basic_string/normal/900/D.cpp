#include<bits/stdc++.h>
using namespace std;
int a[13],t,ans;
const int P=1e9+7;
int qp(int a,int b) {
	int r=1;
	for(; b; b>>=1,a=a*1ll*a%P)if(b&1)r=r*1ll*a%P;
	return r;
}
void dfs(int x,int y,bool b) {
	if(x==t) {
		if(b)ans=(ans+qp(2,y-1))%P;
		else ans=(ans-qp(2,y-1))%P;
		return;
	}
	++x,dfs(x,y/a[x],!b),dfs(x,y,b);
}
int main() {
	int x,y,i;
	scanf("%d%d",&x,&y);
	if(y%x)return puts("0"),0;
	y/=x,x=y;
	for(i=2; i*i<=y; ++i)if(!(y%i)) {
			a[++t]=i;
			do y/=i;
			while(!(y%i));
		}
	if(y>1)a[++t]=y;
	dfs(0,x,1),printf("%d",(ans+P)%P);
	return 0;
}