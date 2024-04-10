#include <iostream>
#include <vector>

#define M 311
#define S 100100
#define p 1000000007
#define long long long

using namespace std;

long n,a[M],d[M],g[M],m=0,x[S],t;
vector<int> h[M]; 
bool u[M],pos=1;

void read(void){
	int q,x,y;
	cin>>n>>q>>t;
	
	for (int i=1; i<=n; ++i)
	cin>>a[i];
	
	while (q--){
		cin>>x>>y;
		g[x]=y;
		d[y]++;
	}
}

void dfs(int t,int v){
	u[v]=1;
	h[t].push_back(v);
	if (g[v])
	dfs(t,g[v]);
}

void pre(void){
	for (int i=1; i<=n; ++i)
	if (d[i]==0)
	dfs(m++,i);
	
	for (int i=1; i<=n; ++i)
	if (!u[i])
	pos=0;	
}

void calc(void){
	for (int i=0; i<m; ++i){
		int n=h[i].size();
		for (int j=1; j<n; ++j)
		a[h[i][j]]+=a[h[i][j-1]];
		
		for (int j=0; j<n-1; ++j)
		t-=a[h[i][j]];
	}
	
	x[0]=1;
	
	for (int i=1; i<=n; ++i)
	for (int j=a[i]; j<=t; ++j){
		x[j]+=x[j-a[i]];
		if (x[j]>=p)
		x[j]-=p;
	}
	
	if (t>=0)
	cout<<x[t];
	else
	cout<<0;
	cout<<"\n";
}

int main()
{
	read();
	pre();
	if (pos)
	calc();
	else
	cout<<"0\n";
	return 0;
}