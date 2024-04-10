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
const int N = 2e5 + 10;
const int Log = 30;
const ll Inf = 2242545357980376863LL;


int a[N], b[N], pa[N], pb[N];

int Main(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> b[i];
	vector<int> A(n), B(n);
	iota(all(A), 1); iota(all(B), 1);
	sort(all(A), [&](int i, int j){ return a[i] > a[j]; });
	sort(all(B), [&](int i, int j){ return b[i] > b[j]; });
	for(int i = 0; i < n; i++) pa[A[i]] = i;
	for(int i = 0; i < n; i++) pb[B[i]] = i;
	
	int poa = 0;
	int pob = 0;
	vector<int> mk(n + 2, 0);
	function<void(int)> DFS = [&](int u){
		if(mk[u]) return ;
		mk[u] = 1;
		// debug(u);
		while(poa < pa[u]){
			int adj = A[poa];
			poa ++;
			DFS(adj);
		}
		while(pob < pb[u]){
			int adj = B[pob];
			pob ++;
			DFS(adj);
		}
	};
	DFS(A[0]);

	for(int i = 1; i <= n; i++) cout << mk[i];
	cout << '\n';
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc;
	cin >> tc;
	while(tc --) Main();
	return 0;
}