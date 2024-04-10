#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define fi first
#define se second
int n,m,k,d[10],g[60][60],dsu[60],p[10],id[10][60];
bool on[10][60],mon[10][60],non[10][60];
int now,mn,nw;
int O,Q;
pii o[1500],q[500];
int find(int x){return dsu[x]==x?x:dsu[x]=find(dsu[x]);}
bool merge(int x,int y){x=find(x),y=find(y);if(x==y)return false;dsu[x]=y;return true;}
const double eps=1e-3;
const double Delta=0.99975;
const double Tin=5000;
double possR(){return 1.0*(rand()*RAND_MAX+rand())/(RAND_MAX*RAND_MAX);}
bool cont[100];
void findoutercontact(int i){
	for(int j=1;j<=n;j++){
		int y=id[i][j];
		if(y<=k&&(p[y]==d[y]||!cont[find(y)]))continue;
		merge(i,y),p[i]++,nw+=g[min(i,y)][max(i,y)],non[min(i,y)][max(i,y)]=true;
		if(y<=k)p[y]++;
		break;
	}
}
void gene(double T){
	nw=0;
	for(int i=1;i<=n;i++)dsu[i]=i,cont[i]=false;
	for(int i=1;i<=k;i++)p[i]=0;
	for(int i=1;i<=k;i++)for(int j=i+1;j<=n;j++)non[i][j]=on[i][j];
	for(int i=1;i<=Q;i++){
		int x=q[i].fi,y=q[i].se;
		if(!non[x][y])continue;
		if(possR()<T){non[x][y]=false;continue;}
		p[x]++;if(y<=k)p[y]++;
		merge(x,y),nw+=g[x][y];
	}
	random_shuffle(q+1,q+Q+1);
	for(int i=1;i<=Q;i++){
		int x=q[i].fi,y=q[i].se;
		if(non[x][y])continue;
		if(p[x]==d[x])continue;
		if(y<=k&&p[y]==d[y])continue;
		if(find(x)==find(y))continue;
		if(possR()>T)continue;
		non[x][y]=true,merge(x,y),nw+=g[x][y],p[x]++;
		if(y<=k)p[y]++;
	}
	for(int i=1;i<=k;i++)for(int j=k+1;j<=n;j++)if(non[i][j])cont[find(i)]=true;
	for(int i=1;i<=k;i++){
		if(cont[find(i)])continue;
		int pos=find(i);
		int spc=-1;
		for(int j=1;j<=k;j++)if(find(j)==pos&&p[j]!=d[j])spc=j;
		if(spc==-1){
			for(int j=1;j<=k;j++){
				if(find(j)!=pos)continue;
				dsu[j]=j,p[j]=0;for(int y=j+1;y<=k;y++)non[j][y]=false;
				cont[j]=false;
				findoutercontact(j);
			}
		}else findoutercontact(spc);
	}
	for(int i=1;i<=O;i++)if(merge(o[i].fi,o[i].se))nw+=g[o[i].fi][o[i].se];
}
void Simulated_Anneal(){
	double T=Tin;
	for(int i=1;i<=k;i++)for(int j=i+1;j<=n;j++)on[i][j]=mon[i][j];
	now=mn;
	while(T>eps){
//		printf("%lf:%d\n",T,now);
		gene(T);
		if(nw<mn){
			mn=now=nw;
			for(int i=1;i<=k;i++)for(int j=i+1;j<=n;j++)on[i][j]=mon[i][j]=non[i][j];
			T*=Delta;
			continue;
		}
		int delta=now-nw;
//		printf("%d,%lf:%lf\n",delta,T,exp(-delta/T));
		if(exp(delta/T)>possR()){
//			printf("%lf:ACCEPTED\n",T);
			now=nw;
			for(int i=1;i<=k;i++)for(int j=i+1;j<=n;j++)on[i][j]=non[i][j];
		}//else printf("%lf:REJECTED\n",T);
		T*=Delta;
	}
} 
void Climbing(){
	for(int t=1;t<=500;t++){
		for(int i=1;i<=k;i++)for(int j=i+1;j<=n;j++)on[i][j]=mon[i][j];
		gene(0.5);
		if(nw<mn){
			mn=nw;
			for(int i=1;i<=k;i++)for(int j=i+1;j<=n;j++)mon[i][j]=non[i][j];
		}
	}
}
int USEDINSORT;
int main(){
	srand(19260817);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++)scanf("%d",&d[i]);
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)scanf("%d",&g[i][j]);
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++)id[i][j]=j;
		for(int j=1;j<i;j++)g[i][j]=g[j][i];
		g[i][i]=0x3f3f3f3f;
		USEDINSORT=i;
		sort(id[i]+1,id[i]+n+1,[](int x,int y){return g[USEDINSORT][x]<g[USEDINSORT][y];});
	}
	for(int i=1;i<=k;i++)for(int j=i+1;j<=n;j++)q[++Q]=make_pair(i,j);
	for(int i=k+1;i<=n;i++)for(int j=i+1;j<=n;j++)o[++O]=make_pair(i,j);
	sort(o+1,o+O+1,[](pii&u,pii&v){return g[u.fi][u.se]<g[v.fi][v.se];});
	gene(Tin);
	mn=nw;for(int i=1;i<=k;i++)for(int j=i+1;j<=n;j++)mon[i][j]=non[i][j];
	for(int i=1;i<=5;i++)Climbing(),Simulated_Anneal();
//	for(int i=1;i<=k;i++){for(int j=1;j<=n;j++)printf("%d ",mon[i][j]);puts("");}
	printf("%d\n",mn);
	return 0;
}