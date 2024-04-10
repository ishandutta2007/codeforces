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

const int Mod = 1000000007LL;
const int N = 1e3 + 10;
const int Log = 30;
const ll Inf = 2242545357980376863LL;

int mk[N][N], T;
int A[N][N];

pii D[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int Main(){
	int n;
	cin >> n;
	
	auto valid = [&](int i, int j){ return (0 <= min(i, j)) && (max(i, j) < n); };

	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> A[i][j];
	int xo = 0;
	T ++;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			vector<pii> adj;
			for(auto [dx, dy] : D){
				int ni = i + dx, nj = j + dy; 
				if(!valid(ni, nj)) continue;
				adj.pb({ni, nj});
			}
			int flg = 1;
			for(auto [x, y] : adj) if(mk[x][y] == T) flg = 0;
			if(!flg) continue;
			xo ^= A[i][j];
			for(auto [x, y] : adj) mk[x][y] = T;
		}
	}

	cout << xo << '\n';
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc;
	cin >> tc;
	while(tc --) Main();
	return 0;
}