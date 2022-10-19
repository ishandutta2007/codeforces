#include<bits/stdc++.h>
#define ll long long
#define N 100015
using namespace std;
struct edge{
	int to,id;
	edge(){}
	edge(int a,int b){to = a;id = b;}
};
vector<edge> e[N]; 
int n,ind[N],num[N],tot = 3;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin >> n;
	memset(num,-1,sizeof(num));
	for(int i = 1;i < n;++i){
		int u,v;
		cin >> u >> v;
		ind[u]++;ind[v]++;
		e[u].push_back(edge(u,i));
		e[v].push_back(edge(v,i));
	}
	for(int i = 1;i <= n;++i){
		if(ind[i] >= 3){
			for(int j = 0;j < 3;++j){
				int v = e[i][j].id;
				num[v] = j;
			}
			for(int j = 1;j < n;++j){
				if(num[j]==-1){
					num[j] = tot++;
				}
			}
			for(int j = 1;j < n;++j){
				cout << num[j] << endl;
			}
			return 0;
		}
	}
	for(int i = 0;i < n-1;++i) cout << i << endl;
	return 0;
}