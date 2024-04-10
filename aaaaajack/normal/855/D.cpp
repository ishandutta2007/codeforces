#include<bits/stdc++.h>
#define N 101000
using namespace std;
int p[N][20],s[N][20];
int dep[N];
inline void go_exp(int &x,int &sx,int i){
	sx+=s[x][i];
	x=p[x][i];
}
void go(int &x,int &sx,int step){
	int i=0;
	while(step){
		if(step&1){
			go_exp(x,sx,i);
		}
		step>>=1;
		i++;
	}
}
int main(){
	int n,x,y,z,q;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&x,&y);
		if(y>=0){
			p[i][0]=x;
			s[i][0]=y;
			dep[i]=dep[x]+1;
		}
		else dep[i]=1;
	}
	for(int i=1;i<20;i++){
		for(int j=1;j<=n;j++){
			p[j][i]=p[p[j][i-1]][i-1];
			s[j][i]=s[j][i-1]+s[p[j][i-1]][i-1];
		}
	}
	scanf("%d",&q);
	while(q--){
		scanf("%d%d%d",&z,&x,&y);
		if(x==y){
			puts("NO");
			continue;
		}
		int sx=0,sy=0,t=0,dx=dep[x],dy=dep[y];
		if(dep[x]>dep[y]){
			go(x,sx,dep[x]-dep[y]);
		}
		else{
			go(y,sy,dep[y]-dep[x]);
		}
		while(dep[x]>=(1<<t)) t++;
		while(t--){
			if(p[x][t]!=p[y][t]){
				go_exp(x,sx,t);
				go_exp(y,sy,t);
			}
		}
		if(x!=y){
			go_exp(x,sx,0);
			go_exp(y,sy,0);
		}
		assert(x==y);
		if(x==0){
			puts("NO");
		}
		else if(z==1){
			if(dep[x]==dx&&sy==0){
				puts("YES");
			}
			else puts("NO");
		}
		else{
			if(sy>0&&dy-dep[y]==sy&&sx==0){
				puts("YES");
			}
			else puts("NO");
		}
	}
	return 0;
}