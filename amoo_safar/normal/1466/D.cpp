// vaziat meshki-ghermeze !
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
const int N = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll w[N];

int Main(){
	int n;
	cin >> n;
	vector<int> deg(n + 1, 0);
	int u, v;
	for(int i = 1; i <= n; i++) cin >> w[i];
	for(int i = 1; i < n; i++){
		cin >> u >> v;
		deg[u] ++;
		deg[v] ++;		
	
	}
	vector<ll> V;
	ll Sm = 0;
	for(int i = 1; i <= n; i++){
		Sm += w[i];
		for(int j = 1; j < deg[i]; j++)
			V.pb(w[i]);
	}
	sort(all(V));
	reverse(all(V));
	cout << Sm;
	for(auto x : V){
		Sm += x;
		cout << " " << Sm;
	}
	cout << '\n';
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	cin >> T;
	while(T --) Main();
	return 0;
}