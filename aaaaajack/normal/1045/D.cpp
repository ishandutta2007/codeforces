#include<bits/stdc++.h>
#define N 100100
using namespace std;
vector<int> g[N],bn[N];
double p[N];
double sn[N];
int main(){
	int n,q,x,y,s;
	double sv=0,se=0,nv;
	scanf("%d",&n);
	s=round(sqrt(n));
	for(int i=0;i<n;i++){
		scanf("%lf",&p[i]);
		p[i]=1-p[i];
		sv+=p[i];
	}
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
		sn[x]+=p[y];
		sn[y]+=p[x];
	}
	for(int i=0;i<n;i++){
		se+=0.5*p[i]*sn[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<g[i].size();j++){
			int k=g[i][j];
			if(g[k].size()>s){
				bn[i].push_back(k);
				sn[i]-=p[k];
			}
		}
	}	
	scanf("%d",&q);
	while(q--){
		scanf("%d%lf",&x,&nv);
		nv=1-nv;
		if(g[x].size()<=s){
			for(int i=0;i<g[x].size();i++){
				y=g[x][i];
				sn[y]+=nv-p[x];
			}
		}
		double tsn=sn[x];
		for(int i=0;i<bn[x].size();i++){
			y=bn[x][i];
			tsn+=p[y];
		}
		se+=(nv-p[x])*tsn;
		sv+=nv-p[x];
		p[x]=nv;
		printf("%f\n",sv-se);
	}
	return 0;
}