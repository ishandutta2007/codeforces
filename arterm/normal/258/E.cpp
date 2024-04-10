#include <iostream>
#include <vector>

#define M 100100

using namespace std;

vector<int> g[M],q[M],d[M];
int n,m,t=1,l[M],r[M],c[M];
int add[4*M],tree[4*M];
bool u[M];

int get(int v, int l, int r){
	if (add[v]>0)
	return r-l+1;
	return tree[v];
}

void fuck(int v, int l, int r){
	if (add[v]==0)
	if (l==r)
	tree[v]=0;
	else{
		int m=(l+r)/2;
		tree[v]=get(2*v,l,m)+get(2*v+1,m+1,r);
	}		
}

int get(int v, int l, int r, int le, int re){
	
	if (add[v]>0)
	return re-le+1;
	
	if (le==l && r==re)
	return get(v,l,r);
	
	int m=(l+r)/2;
	
	if (re<=m)
	return get(2*v,l,m,le,re);
	
	if (m+1<=le)
	return get(2*v+1,m+1,r,le,re);
	
	return get(2*v,l,m,le,m)+get(2*v+1,m+1,r,m+1,re);
}

void push(int v, int l, int r, int le, int re, int val){
	
	if (le==l && r==re){
		add[v]+=val;
		fuck(v,l,r);
		return ;
	}
	
	int m=(l+r)/2;
	if (re<=m)
	push(2*v,l,m,le,re,val);
	if (m+1<=le)
	push(2*v+1,m+1,r,le,re,val);
	
	if (le<=m && m+1<=re){
		push(2*v,l,m,le,m,val);
		push(2*v+1,m+1,r,m+1,re,val);
	}
	
	fuck(v,l,r);
}

void read(void){
	cin>>n>>m;
	for (int i=1,a,b; i<n; ++i){
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
}

void dfs(int v){
	u[v]=1;
	l[v]=t++;
	for (int i=0; i<(int)g[v].size(); ++i){
		int to=g[v][i];
		if (!u[to])
		dfs(to),d[v].push_back(to);
	}
	r[v]=t-1;
}

void store(void){
	for (int i=0,a,b; i<m; ++i){
		cin>>a>>b;
		q[a].push_back(b);
		q[b].push_back(a);
	}
}

void run(int v){
	
	for (int i=0; i<(int)q[v].size(); ++i){
		int to=q[v][i];
		push(1,1,n,l[v],r[v],1);
		push(1,1,n,l[to],r[to],1);
	}
	
	c[v]=get(1,1,n,1,n)-1;
	if (c[v]==-1)
	c[v]=0;
	
	for (int i=0; i<(int)d[v].size(); ++i){
		int to=d[v][i];
		run(to);	
	}
	
	for (int i=0; i<(int)q[v].size(); ++i){
		int to=q[v][i];
		push(1,1,n,l[v],r[v],-1);
		push(1,1,n,l[to],r[to],-1);
	}
}

void test(void){
	int t;
	cin>>t>>n;
	for (int i=0,a,b,c,v; i<t; ++i){
		cin>>c>>a>>b>>v;
		if (c==1)
		push(1,1,n,a,b,v);
		else
		cout<<get(1,1,n,a,b)<<"\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	//test();
	read();
	dfs(1);
	store();
	
	run(1);
	for (int i=1; i<=n; ++i,cout<<" ")
	cout<<c[i];
}