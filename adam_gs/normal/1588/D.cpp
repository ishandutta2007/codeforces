#pragma GCC option("arch=native","tune=native","no-zero-upper") 
#pragma GCC target("avx2","popcnt","rdrnd","bmi2")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int INF=1e9+7;
vector<vector<pair<int,int>>>G[52];
vector<int>odl[52];
vector<pair<int,int>>nxt[52];
int ans, x1, x2;
void DFS(int a, int b) {
	odl[a][b]=1;
	for(auto i : G[a][b]) {
		if(!odl[i.st][i.nd]) DFS(i.st, i.nd);
		if(odl[i.st][i.nd]+1>odl[a][b]) {
			odl[a][b]=odl[i.st][i.nd]+1;
			nxt[a][b]={i.st, i.nd};
		}
	}
	if(odl[a][b]>ans) {
		ans=odl[a][b];
		x1=a;
		x2=b;
	}
}
void solve() {
	rep(i, 52) {
		G[i].clear();
		odl[i].clear();
		nxt[i].clear();
	}
	ans=0;
	x1=-1;
	x2=-1;
	int n;
	cin >> n;
	string T[n];
	rep(i, n) cin >> T[i];
	vector<vector<int>>V[52];
	rep(i, 26) {
		int A[n][2];
		rep(j, n) A[j][0]=A[j][1]=-1;
		rep(j, n) {
			rep(l, T[j].size()) if(T[j][l]=='a'+i) {
				if(A[j][0]==-1) A[j][0]=l+1;
				else A[j][1]=l+1;
			}
		}
		rep(j, 1<<n) {
			vector<int>S;
			rep(l, n) {
				if(j&(1<<l)) S.pb(A[l][1]);
				else S.pb(A[l][0]);
			}
			V[i].pb(S);
		}
	}
	rep(i, 26) {
		int A[n][2];
		rep(j, n) A[j][0]=A[j][1]=-1;
		rep(j, n) {
			rep(l, T[j].size()) if(T[j][l]=='A'+i) {
				if(A[j][0]==-1) A[j][0]=l+1;
				else A[j][1]=l+1;
			}
		}
		rep(j, 1<<n) {
			vector<int>S;
			rep(l, n) {
				if(j&(1<<l)) S.pb(A[l][1]);
				else S.pb(A[l][0]);
			}
			V[26+i].pb(S);
		}
	}
	vector<pair<int,int>>xd;
	rep(i, 52) {
		rep(j, V[i].size()) G[i].pb(xd);
	}
	rep(i, 52) rep(j, 52) {
		int p=0;
		rep(l, V[i].size()) {
			int akt=0;
			rep(k, V[i][l].size()) {
				if(V[j][akt][k]<=V[i][l][k]) {
					akt+=1<<k;
				}
			}
			bool ok=true;
			rep(k, V[i][l].size()) if(V[j][akt][k]<=V[i][l][k]) ok=false;
			if(ok) G[i][l].pb({j, akt});
		}
	}
	rep(i, 52) {
		rep(j, V[i].size()) {
			bool ok=true;
			rep(l, V[i][j].size()) if(V[i][j][l]==-1) ok=false;
			if(ok) odl[i].pb(0);
			else odl[i].pb(-INF);
			nxt[i].pb({-1, -1});
		}
	}
	rep(i, 52) {
		rep(j, V[i].size()) if(!odl[i][j]) DFS(i, j);
	}
	string w="";
	pair<int,int>zle={-1, -1};
	while(x1!=-1 && nxt[x1][x2]!=zle) {
		if(x1<26) w+=char('a'+x1);
		else w+=char('A'+x1-26);
		int p1=nxt[x1][x2].st, p2=nxt[x1][x2].nd;
		x1=p1;
		x2=p2;
	}
	if(x1!=-1) {
		if(x1<26) w+=char('a'+x1);
		else w+=char('A'+x1-26);
	}
	cout << ans << '\n' << w << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	cin >> _;
	while(_--) solve();
}