#include <iostream>
#include <vector>

#define M 100100
#define long long long

using namespace std;

long n,a[M],d[6][M];
bool u[M];
vector<int> g[M],t[M];
unsigned long ans=0;

void read(void){
	cin>>n;
	for (int i=1,a,b; i<n; ++i){
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
}

void dfs(int v){
	u[v]=1;
	a[v]=1;

	
		
	for (int i=0,to; i<(int)g[v].size(); ++i){
		to=g[v][i];
		if (!u[to]){
			dfs(to);
			a[v]+=a[to];
			t[v].push_back(a[to]);
		}
	}
	
	
	t[v].push_back(n-a[v]);
	
}

void kill(int v){
	
	for (int i=0; i<(int)t[v].size(); ++i){
		long x=t[v][i];
		d[4][i+1]=d[4][i]+d[3][i]*x;
		d[3][i+1]=d[3][i]+d[2][i]*x;
		d[2][i+1]=d[2][i]+d[1][i]*x;
		d[1][i+1]=d[1][i]+x;
	}
	
	int k=t[v].size();
	
	ans-=d[4][k];
	ans-=d[3][k];
	
	
}

int main()
{
	read();
	dfs(1);

	
	ans=((((n*(n-1)/2)*(n-2))/3)*(n-3))/4;
	
	for (int i=1; i<=n; ++i)
	kill(i);
	
	cout<<2*ans<<"\n";
	
	return 0;
}