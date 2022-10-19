#include<bits/stdc++.h>

using namespace std;

#define F1(i,n) for(int i = 1; i <= n; i++)
#define F0(i,n) for(long long i = 0; i < n; i++)
#define F first
#define S second
#define INF 1000000000
#define mod 1000000007
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;

void dfs(int x, vvi& ppg, vvi& gpp, vector<bool>& visitados, vi& colores, int marca){
	if(colores[x] != 0) return;
	colores[x] = marca;

	F0(i, gpp[x].size()){
		if(visitados[gpp[x][i]]) continue;
		visitados[gpp[x][i]] = true;
		F0(j, ppg[gpp[x][i]].size()){
			dfs(ppg[gpp[x][i]][j], ppg, gpp, visitados, colores, marca);
		}
	}
}

int main(){
	int n,m;
	cin>>n>>m;
	vvi ppg(m);
	vvi gpp(n+1);
	F0(i,m){
		int k;
		cin>>k;
		F0(j,k){
			int l;
			cin>>l;
			ppg[i].pb(l);
			gpp[l].pb(i);
		}
	}

	vi res(n+1);
	vi resG(m);
	vector<bool> visitados(m,false);
	vi colores(n+1);
	F1(i, n){
		dfs(i, ppg, gpp, visitados, colores, i);
	}

	vi mapa(n+1);

	F1(i, n){
		mapa[colores[i]]++;
	}
	F1(i,n) res[i] = mapa[colores[i]];

	F1(i, n) cout<<res[i]<<' ';
	cout<<'\n';
}