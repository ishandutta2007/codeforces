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

const ll Mod = 1000000007LL;
const int N = 85; // Wow !
const int Inf = 1e9 + 10;
const ll Log = 30;

vector<int> B[N][N], C;
int K = 6;

int n, L, d[N][N];

int a, b;
bool CMP(int i, int j){
	return d[a][i] + d[i][b] < d[a][j] + d[j][b];
}
vector<int> Q;

int mk[N];
int Calc(){
	for(auto x : Q) mk[x] = 1;
	int M = Q.size();
	int idx, res = 0;
	for(int i = 1; i < M; i++){
		idx = -1;
		for(auto y : B[Q[i - 1]][Q[i]]){
			if(!mk[y]){
				idx = y;
				break;
			}
		}
		if(idx == -1){
			for(auto x : Q) mk[x] = 0;		
			return Inf;
		}
		//cerr << idx << '\n';
		res += d[Q[i - 1]][idx] + d[idx][Q[i]];
	}
	for(auto x : Q) mk[x] = 0;		
	return res;
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> n >> L;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			cin >> d[i][j];
	/*
	n = 80;
	L = 10;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			d[i][j] = rand();
	*/
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			C.clear();
			for(int k = 1; k <= n; k++){
				if(k == i || k == j) continue;
				C.pb(k);
			}
			a = i; b = j;
			sort(all(C), CMP);
			int rem = K;
			for(auto x : C){
				if(!rem) break;
				rem --;
				B[i][j].pb(x);
			}
		}
	}
	int pos = 1;
	int T = (L - 2) / 2;
	for(int i = 0; i < T; i++) pos *= n;
	int ans = Inf;
	for(int i = 0; i < pos; i++){
		Q.clear();
		Q.pb(1);
		int I = i;
		for(int j = 0; j < T; j++){
			Q.pb((I%n) + 1);
			I /= n;
		}
		Q.pb(1);
		ans = min(ans, Calc());
		//if(Calc() == 4){
			//for(auto x : Q) cerr << x << ' ';
				//cerr << '\n';
		//	break;
		//}
	}
	//Q = {1, 2, 1, 2, 1};
	//cerr << "!! " << Calc() << '\n';
	cout << ans << '\n';
	return 0;
}