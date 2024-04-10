#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2222;
const LL inf = 1e18;
struct edge{
	int pr;
	int to;
	LL cap;
}e[111111];
int tot=1,la[N];
void clr(){
	tot=1;
	memset(la,0,sizeof(la));
}
void adde(int x,int y,LL z){
	e[++tot].pr=la[x];
	la[x]=tot;
	e[tot].to=y;
	e[tot].cap=z;
}
void addf(int x,int y,LL z=inf){//cout<<x<<' '<<y<<' '<<z<<endl;
	adde(x,y,z);
	adde(y,x,0);
}
int d[N];
int bfs(int s,int t){
	queue<int> Q;
	int i,x,y;
	memset(d,0,sizeof(d));
	d[s]=1;
	Q.push(s);
	while(!Q.empty()){
		x=Q.front();
		Q.pop();
		for(i=la[x];i;i=e[i].pr){
			if(!e[i].cap)
				continue;
			y=e[i].to;
			if(!d[y]){
				d[y]=d[x]+1;
				Q.push(y);
			}
		}
	}
	return d[t];
}
LL dfs(int s,int t,LL f){
	if(s==t)
		return f;
	int i,y;
	LL x,r=0;
	for(i=la[s];i;i=e[i].pr){
		if(!e[i].cap||!f)
			continue;
		y=e[i].to;
		if(d[y]!=d[s]+1)
			continue;
		x=dfs(y,t,min(f,e[i].cap));
		if(x){
			f-=x;
			r+=x;
			e[i].cap-=x;
			e[i^1].cap+=x;
		}
	}
	if(!r)
		d[s]=0;
	return r;
}
LL maxflow(int s,int t){
	LL x,r=0;
	while(bfs(s,t)){
		x=dfs(s,t,inf);
		if(x)
			r+=x;
		else
			break;
	}
	return r;
}
int s,t;
int n,x[N],y[N],w[N],z[N];
int main(){
	int i,j;
	LL o;
	o=0;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>x[i]>>y[i]>>w[i];
		if(x[i]&1)
			z[i]+=2;
		if(y[i]&1)
			z[i]++;
		o+=w[i];
	}
	s=0,t=1;
	for(i=1;i<=n;i++){
		addf(i*2,i*2+1,w[i]);
		if(z[i]==2)
			addf(s,i*2);
		if(z[i]==3)
			addf(i*2+1,t);
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(abs(x[i]-x[j])<=1-abs(y[i]-y[j])){
				if(z[i]==2&&z[j]==0)
					addf(i*2+1,j*2);
				if(z[i]==0&&z[j]==1)
					addf(i*2+1,j*2);
				if(z[i]==1&&z[j]==3)
					addf(i*2+1,j*2);
			}
		}
	}
	cout<<o-maxflow(s,t);
	return 0;
}