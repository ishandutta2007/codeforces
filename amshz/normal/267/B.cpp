# include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair < pair <int, int> , int> ppi;

# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

const ll md = 1e9+7;

ll gcd(ll a, ll b){ if (b == 0) return a; return gcd(b, a%b);}
ll lcm(ll a, ll b){ return a*b/gcd(a, b);}
ll pmd(ll a, ll b){
	if (b == 1) return (a+md)%md;
	if (b%2 == 0) return (pmd(a*a, b/2)+md)%md;
	else return (a*pmd(a*a, b/2)+md)%md;
}

const int xn = 1e2+10;
const int xk = 10;

struct edge{
	int V, U;
	bool mark;
};

int n, dx, d[xk], ind;
vector <pii> adj[xk];
vector <int> ans;
edge e[xn];

void DFS(int v){
	
	bool vis = true;
	//dx = v;
	//cout << v << sep;
	
	for (int i=0; i<adj[v].size(); i++){
		int u = adj[v][i].F, k = adj[v][i].S;
		if (e[k].mark) continue;
		
		e[k].mark = true;
		DFS(u);
		dx = k;
		vis = false;
		//break;
	}
	
	if (1) ans.pb(v);
	
	//dx = v;
}


int main(){
	fast_io;
	
	cin >> n;
	int x, y;
	for (int i=1; i<=n; i++){
		cin >> x >> y;
		adj[x].pb({y, i}), adj[y].pb({x, i});
		e[i].V = x, e[i].U = y;
		d[x]++, d[y]++;
	}
	//for (int i=0; i<adj[4].size(); i++) cout << e[adj[4][i].S].mark << sep;
	//cout << endl;
	
	vector <int> odd;
	for (int i=0; i<=6; i++) if (d[i]%2 == 1) odd.pb(i);
	
	if (odd.size() == 0){
		for (int i=0; i<=6; i++){
			if (d[i] > 0){
				DFS(i);
				//cout << i << endl;
				break;
			}
		}
	}
	else if (odd.size() == 2) DFS(odd[0]);
	
	else{
		cout << "No solution" << endl;
		return 0;
	}
	//cout << ans.size() << endl;
	if (ans.size()-1 < n){
		cout << "No solution" << endl;
		return 0;
	}
	
	for (int i=0; i<=n; i++) e[i].mark = false;
	
	for (int i=0; i<ans.size()-1; i++){
		int v = ans[i], u = ans[i+1];
		
		for (int j=1; j<=n; j++){
			if (e[j].mark) continue;
			
			if (v == e[j].V && u == e[j].U){
				cout << j << " +" << endl;
				e[j].mark = true;
				break;
			}
			if (v == e[j].U && u == e[j].V){
				cout << j << " -" << endl;
				
				e[j].mark = true;
				break;
			}
		}
	}
	
	
	return 0;
}