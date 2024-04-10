#include<cstdio>
#define N (1<<21)
#define M (1<<20)
using namespace std;
int f[N]={0},y[N]={0},x[M]={0};
int sit[M]={0};
int pos=M;
void add(int n,int x){
	while(n<N){
		f[n]+=x;
		n+=n&-n;
	}
}
int bs(int n){
	int r=M,now=0,os=0;
	while(r){
		while(r&&(os+r>=N||now+f[os+r]>=n)) r>>=1;
		if(r){
			os+=r;
			now+=f[os];
		}
	}
	return os+1;
}
int main(){
	int n,m,i,p,q,t,r;
	bool flag=true;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) y[M+i]=i,add(M+i,1);
	while(m--){
		scanf("%d%d",&p,&q);
		t=bs(q);
		if(x[y[t]]&&x[y[t]]!=p){
			flag=false;
		}
		else{
			x[y[t]]=p;
			if(sit[p]&&sit[p]!=y[t]) flag=false;
			sit[p]=y[t];
			add(t,-1);
			add(pos,1);
			y[pos--]=y[t];
		}
	}
	r=1;
	if(!flag) printf("-1\n");
	else{
		for(i=1;i<=n;i++){
			if(x[i]) printf("%d",x[i]);
			else{
				while(sit[r]) r++;
				printf("%d",r);
				sit[r]=i;
			}
			if(i==n) putchar('\n');
			else putchar(' ');
		}
	}
	return 0;
}