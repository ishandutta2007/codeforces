#include<cstdio>
#define N 100100
#define Q 1000000007
using namespace std;
int f[N],g[N];
void find(int x){
	if(f[x]==x) return;
	find(f[x]);
	g[x]^=g[f[x]];
	f[x]=f[f[x]];
}
int check(int x,int y,char c){
	int v=(c=='o');
	find(x);
	find(y);
	if(f[x]==f[y]){
		return (g[x]^g[y])==v;
	}
	else{
		g[f[x]]=g[x]^g[y]^v;
		f[f[x]]=f[y];
		return -1;
	}
}
int main(){
	int i,n,k,x,y,l,r,t,m;
	char c;
	bool flag=false;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n+2;i++) f[i]=i;
	m=n;
	while(k--){
		scanf("%d %d %c",&x,&y,&c);
		l=x-(y-1);
		r=x+(y-1);
		if(l<=0) l=-l+2;
		if(r>n) r=2*n-r;
		r+=2;
		t=check(l,r,c);
		if(t==-1) m--;
		else if(t==0) flag=true;
	}
	if(flag) printf("%d\n",0);
	else{
		y=1;
		x=2;
		while(m){
			if(m&1) y=1LL*y*x%Q;
			x=1LL*x*x%Q;
			m>>=1;
		}
		printf("%d\n",y);
	}
	return 0;
}