#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

const int N = 72;

typedef bitset<257> X;
typedef pair<X, X> con;

void Add(con& A, con& B){ // A += B
	con res;
	res.F = (A.S & B.S) ^ A.F ^ B.F;
	res.S = (A.F & B.F) ^ A.S ^ B.S;
	X AND = res.F & res.S;
	res.F ^= AND;
	res.S ^= AND;
	A = res;
}

vector< con > C;
con blank;
void Set(con& A, int idx, int v){
	v %= 3;
	A.F[idx] = v & 1;
	A.S[idx] = v >> 1;
}
int Get(con& A, int idx){
	return A.F[idx] + 2 * A.S[idx];
}
int ed[N][N];
const int M = 300;
int ans[M];
int Main(){
	C.clear();
	int n, m;
	cin >> n >> m;
	memset(ed, -1, sizeof ed);
	memset(ans, -1, sizeof ans);
	int u, v, w;
	for(int i = 0; i < m; i++){

		cin >> u >> v >> w;
		u--; v--;
		ed[u][v] = ed[v][u] = i;
		if(w != -1){
			con A = blank;
			Set(A, 256, w % 3);
			Set(A, i, 1);
			C.pb(A);
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			if(ed[i][j] == -1) continue;
			for(int k = j + 1; k < n; k++){
				if(ed[i][k] == -1) continue;
				if(ed[j][k] == -1) continue;
				con A = blank;
				Set(A, ed[i][j], 1);
				Set(A, ed[i][k], 1);
				Set(A, ed[j][k], 1);
				C.pb(A);
			}
		}
	}
	int row = 0;
	for(int _ = 0; _ < m; _++){
		int idx = -1;
		for(int j = row; j < (int) C.size(); j++){
			if(Get(C[j], _) == 0) continue;
			idx = j;
		}
		if(idx == -1) continue;
		if(idx != row) swap(C[row], C[idx]);
		if(C[row].S[_]) Add(C[row], C[row]);
		for(int j = row+1; j < (int)C.size();j++){
			while(Get(C[j], _))
				Add(C[j], C[row]);
		}
		row ++;
	}
	vector<pii> ava;
	// cerr << "!!\n";
	// for(auto &x : C){
	// 	for(int i = 0; i < m; i++) cerr << Get(x, i) << " + ";
	// 	cerr << " = " << Get(x, 256) << '\n';
	// }
	// cerr << "!!\n";
	for(int i = C.size() - 1; i >= 0; i--){
		ava.clear();
		int nw = Get(C[i], 256);
		for(int j = 0; j < m; j++){
			if(Get(C[i], j) == 0) continue; 
			if(ans[j] != -1){
				nw -= ans[j] * Get(C[i], j);
				nw %= 3;
				nw += 3;
				nw %= 3;
				continue;
			}
			ava.pb({j, Get(C[i], j)});
		}
		// debug(ava.size());
		if(ava.empty()){
			if(nw == 0) continue;
			return cout << "-1\n", 0;
		}
		for(int j = 1; j < (int) ava.size(); j++)
			ans[ava[j].F] = 0;
		ans[ava[0].F] = (ava[0].S * nw) % 3;
	}
	for(int i = 0; i < m; i++) if(ans[i] == -1) ans[i] = 1;
	for(int i = 0; i < m; i++) cout << (ans[i] == 0 ? 3 : ans[i]) << ' ';
	cout << '\n';
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc = 1;
	cin >> tc;
	while(tc --) Main();
	return 0;
}
/*
	1
	5 10
	1 2 1
	1 3 -1
	1 4 2
	1 5 -1
	2 3 -1
	2 4 3
	2 5 2
	3 4 1
	3 5 2
	4 5 3

*/