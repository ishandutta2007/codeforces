#include <iostream>

#define M 200200
#define long long long

using namespace std;

long n,a[M],ans[2][M],u[2][M];
bool h[2][M],g[2][M];

void dfs(bool t, int v){
	u[t][v]=2;
	
	ans[t][v]=a[v];
	
	int to=v+(t ? a[v]:-a[v]);
	
	if (to<=0 || n<to)
	return;
	
	if (to==1){
		h[t][v]=1;
		g[t][v]=!t;
		return;
	}
	
	if (u[!t][to]==1){
		ans[t][v]=-1;
		return;
	}
	
	u[t][v]=1;
	
	if (u[!t][to]==0)
	dfs(!t,to);
	
	u[t][v]=2;
	
	if (ans[!t][to]!=-1)
	ans[t][v]+=ans[!t][to];
	else
	ans[t][v]=-1;
	
	h[t][v]=h[!t][to];
	g[t][v]=g[!t][to];
}

void read(void){
	cin>>n;
	for (int i=2; i<=n; ++i)
	cin>>a[i];
	
	for (int i=2; i<=n; ++i)
	for (int j=0; j<=1; ++j)
	if (u[j][i]==0)
	dfs(j,i);
}

void kill(void){
	for (int i=2; i<=n; ++i){
		long y=ans[0][i];
		
		if (!h[0][i]){
			if (y==-1)
			cout<<"-1\n";
			else
			cout<<y+i-1<<"\n";
			continue;
		}
		
		if (y==-1 || g[0][i]){
			cout<<"-1\n";
			continue;
		}
		
		cout<<y+2*i-2<<"\n";
	}
}

int main()
{
	read();
	kill();
	return 0;
}