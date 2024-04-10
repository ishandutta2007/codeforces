#include<bits/stdc++.h>

#define x first
#define y second

using namespace :: std;

typedef pair<int,int>vec;
const int N=5e5+5;

struct edge{
	edge* s;
	int v,w;
}e[N*2];

edge *o=e,*h[N];

void ins(int u,int v,int w){
	edge s={h[u],v,w};
	edge t={h[v],u,w};
	*(h[u]=o++)=s;
	*(h[v]=o++)=t;
}

typedef int arr[N];
arr d,p,f,r,v,c;
int a,b=-1,k,q=1e9;

vec dfs1(int u,int f,int d){
	vec s(d,u);
	for(edge*i=h[u];i;i=i->s)
		if(i->v^f&&!v[i->v])
			s=max(s,dfs1(i->v,u,d+i->w));
	return s;
}

vec dfs2(int u){
	vec s(d[u],u);
	for(edge*i=h[u];i;i=i->s)
		if(i->v^p[u]){
			d[i->v]=d[p[i->v]=u]+i->w;
			r[i->v]=i->w;
			s=max(s,dfs2(i->v));
		}
	return s;
}

int main(){
	struct{
		operator int(){
			int x;
			cin>>x;
			return x;
		}
	}it;
	int n=it,m=it;
	for(int i=1;i<n;++i){
		int u=it,v=it;
		ins(u,v,it);
	}
	int s=dfs2(dfs1(1,0,0).y).y;
	for(int i=s;i;i=p[i])
		v[i]=1;
	for(int i=s;i;i=p[i])
		f[i]=dfs1(i,0,0).x;
	int u=s,v=s;
	for(;v;++k,v=p[v]){
		while(k+1>m){
			if(c[a]==f[u])++a;
			--k,u=p[u];
		}
		while(a<=b&&c[b]<f[v])
			--b;
		c[++b]=f[v];
		q=min(q,max(c[a],max(d[s]-d[u],d[v])));
	}
	cout<<q<<endl;
        return 0;
}