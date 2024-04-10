#include <iostream>
#include <vector>

#define M 307
#define long long long

using namespace std;

long n,p[M],sa[M],a[M],b[M],sb[M],ve,e,d[M],td;
vector<int> g[M],xa,ya,da;
bool u[M];

void ini(void){
	for (int i=0; i<M; ++i)
	p[i]=i;
}

int get(int x){
	return p[x]= x==p[x] ? x:get(p[x]);
}

void uni(int x, int y){
	x=get(x);
	y=get(y);
	p[y]=x;
	sa[x]+=sa[y];
	sb[x]+=sb[y];
}

void read(void){
	cin>>n>>ve>>e;
	for (int i=1; i<=n; ++i)
	cin>>a[i],sa[i]=a[i];
	for (int i=1; i<=n; ++i)
	cin>>b[i],sb[i]=b[i];
	
	ini();
	
	for (int i=0,x,y; i<e; ++i){
		cin>>x>>y;
		if (get(x)!=get(y)){
			uni(x,y);
			g[x].push_back(y);
			g[y].push_back(x);
			d[x]++;
			d[y]++;
		}
	}
}

bool pos(void){
	for (int i=1; i<=n; ++i)
	if (p[i]==i && sa[i]!=sb[i])
	return 0;
	return 1;
}

void dfs(int v){
	u[v]=1;
	for (int i=0; i<(int)g[v].size(); ++i){
		int to=g[v][i];
		
		if (u[to] || d[to]<=0)
		continue;
		dfs(to);
		
		long v1;
		
		if (td==v)
		v1=b[v];
		else
		v1=ve;
		
		long d=min((v1-a[v]),a[to]);
		a[v]+=d;
		a[to]-=d;
		xa.push_back(to);
		ya.push_back(v);
		da.push_back(d);
	}
}

void mdfs(int v){
	u[v]=1;
	for (int i=0; i<(int)g[v].size(); ++i){
		int to=g[v][i];
		
		if (u[to] || d[to]<=0)
		continue;
		mdfs(to);
		
		long v1;
		if (td==v)
		v1=b[v];
		else
		v1=0;
		
		long d=min((a[v]-v1),(ve-a[to]));
		a[v]-=d;
		a[to]+=d;
		ya.push_back(to);
		xa.push_back(v);
		da.push_back(d);
	}
}

void kill(void){
	for (int i=1; i<=n; ++i){
		
		for (int j=1; j<=n; ++j)
		u[j]=0;
		
		for (int j=1; j<=n; ++j)
		if (d[j]==1){
			td=j;
			if (a[j]<=b[j])	
			dfs(j);
			else
			mdfs(j);
			d[j]=0;
			for (int k=0; k<(int)g[j].size(); ++k){
				int to=g[j][k];
				if (d[to]>=1)
				d[to]--;
			}
			break;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	read();
	if (pos()){
		kill();
		cout<<xa.size()<<"\n";
		for (int i=0; i<(int)xa.size(); ++i)
		cout<<xa[i]<<" "<<ya[i]<<" "<<da[i]<<"\n";
	}
	else
	cout<<"NO\n";
	return 0;
}