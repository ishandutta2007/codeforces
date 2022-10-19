#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=207;
vector<int>V[LIM*LIM];
int mt[LIM*LIM], odw[LIM*LIM], S[LIM*LIM], dx[]={1, 0, -1, 0}, dy[]={0, 1, 0, -1}, n, m;
string T[LIM];
bool ok(int a, int b) {
	return 0<=a && a<b && 0<=b && b<m;
}
bool DFS(int x) {
	if(odw[x]) return false;
	odw[x]=1;
	for(auto i : V[x]) if(mt[i]==-1 || DFS(mt[i])) {
		mt[i]=x;
		return true;
	}
	return false;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m, ans=0;
	cin >> n >> m;
	rep(i, n) {
		cin >> T[i];
		rep(j, m) if(T[i][j]=='#') ++ans;
	}
	rep(i, n) rep(j, m) if(T[i][j]=='#') {
		if(i<n-1 && T[i+1][j]=='#') {
			--ans;
			if(j>0 && T[i+1][j-1]=='#') {
				V[i*m+j].pb((i+1)*m+j-1);
			}
			if(j<m-1 && T[i+1][j+1]=='#') {
				V[i*m+j].pb((i+1)*m+j);
			}
		}
		if(i>0 && T[i-1][j]=='#') {
			if(j>0 && T[i-1][j-1]=='#') {
				V[(i-1)*m+j].pb((i-1)*m+j-1);
			}
			if(j<m-1 && T[i-1][j+1]=='#') {
				V[(i-1)*m+j].pb((i-1)*m+j);
			}
		}
		if(j<m-1 && T[i][j+1]=='#') --ans;
	}
	rep(i, n*m) mt[i]=-1;
	bool ok=true;
	while(ok) {
		ok=false;
		rep(i, n*m) odw[i]=0;
		rep(i, n*m) {
			if(!S[i] && DFS(i)) {
				S[i]=1;
				ok=true;
				++ans;
			}
		}
	}
	cout << ans << '\n';
}