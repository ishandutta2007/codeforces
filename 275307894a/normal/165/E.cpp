#include<cstdio>
#include<cstring>
using namespace std;
int n,m=(1<<22)-1,k,x,y,z,ans[5000039],a[1000039];
inline void read(int &x){
	char s=getchar();x=0;
	while(s<'0'||s>'9') s=getchar();
	while(s>='0'&&s<='9') x=x*10+s-48,s=getchar();
}
inline void print(int x){
	if(x<0){putchar('-');print(-x);return;}
	if(x>9) print(x/10);
	putchar(x%10+48);
}
int main(){
	register int i,j,now;
	scanf("%d",&n);memset(ans,-1,sizeof(ans));
	for(i=1;i<=n;i++) read(a[i]),ans[a[i]]=a[i];
	for(i=0;i<=m;i++){
		now=i;
		while(now){
			if(~ans[i^(now&-now)]) {ans[i]=ans[i^(now&-now)];break;}
			now-=now&-now;
		} 
	}
	for(i=1;i<=n;i++) print(ans[m^a[i]]),putchar(' ');
}