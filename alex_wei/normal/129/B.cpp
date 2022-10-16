#include<bits/stdc++.h>
using namespace std;
int n,m,in[105],pd[105],cnt;
vector <int> c[105],pop;
bool check()
{
	pop.clear();
	for(int i=1;i<=n;i++)
		if(in[i]==1&&!pd[i])
			pop.push_back(i);
	return pop.size()>0;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		c[u].push_back(v);
		c[v].push_back(u);
		in[u]++;
		in[v]++;
	}
	while(check()){
		cnt++;
		for(int l=0;l<pop.size();l++){
			int i=pop[l];
			pd[i]=1;
			for(int j=0;j<c[i].size();j++){
				int to=c[i][j];
				if(!pd[to])
					in[to]--;
			}
		}
	}
	cout<<cnt;
	return 0;
}