#include<bits/stdc++.h>
#define N 500100
#define K 50
using namespace std;
double lt[N][K];
double m[K];
int p[N];
int main(){
	int q,tp,v,now=1;
	scanf("%d",&q);
	for(int i=0;i<K;i++) lt[1][i]=1;
	while(q--){
		scanf("%d%d",&tp,&v);
		if(tp==1){
			p[++now]=v;
			for(int i=0;i<K;i++) lt[now][i]=1;
			double r=1;
			for(int i=0,u=v,pre=now;i<K&&u>0;i++,pre=u,u=p[u]){
				if(!i) r*=lt[u][i]*0.5;
				else r*=lt[u][i]*0.5/(0.5+0.5*lt[pre][i-1]);
				m[i]=r;
			}
			for(int i=0,u=v;i<K&&u>0;i++,u=p[u]){
				lt[u][i]-=m[i];
			}
		}
		else{
			double ans=0;
			for(int i=0;i<K;i++){
				ans+=(1-lt[v][i]);
			}
			printf("%.12f\n",ans);
		}
	}
	return 0;
}