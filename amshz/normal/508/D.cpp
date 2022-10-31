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

const int xn = 2e5+10;
const int xk = 10;

struct edge{
	int V, U;
	bool mark;
};

int n;
int t1, t2, t3, t4;
map <string, int> d;
map <string, vector <string > > adj;
map <string, int> p;
vector <string> ans;
map <string, int> cnt;
vector <string> vertex;

void DFS(string v){
	//cout << v.
	while (p[v] < adj[v].size()){
		string u = adj[v][p[v]];
		p[v]++;
		DFS(u);
	}
	
	ans.pb(v);
}


int main(){
	fast_io;
	
	cin >> n;
	string a;
	
	for (int i=0; i<n; i++){
		cin >> a;
		string x = "", y = "";
		x += a[0], x += a[1], y += a[1], y += a[2];
		swap(x, y);
		adj[x].pb(y), d[x]++, d[y]--;
		if (cnt[x] == 0) vertex.pb(x);
		cnt[x]++;
		if (cnt[y] == 0) vertex.pb(y);
		cnt[y]++;
	}
	
	for (int i=0; i<vertex.size(); i++){
		if (d[vertex[i]] == 1) t1++;
		else if (d[vertex[i]] == -1) t2++;
		else if (d[vertex[i]] != 0) t3++;
		
		//cout << vertex[i] << sep;
	}
	
	if (t3){
		cout << "NO" << endl;
		return 0;
	}
	else if (t1 || t2){
		if (t1 == 1 && t2 == 1){
			for (int i=0; i<vertex.size(); i++){
				if (d[vertex[i]] == 1){
					DFS(vertex[i]);
					break;
				}
			}
		}
		else{
			cout << "NO" << endl;
			return 0;
		}
	}
	else{
		DFS(vertex[0]);
	}
	
	if (ans.size() <= n){
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	
	cout << ans[0];
	for (int i=1; i<ans.size(); i++) cout << ans[i][1];
	cout << endl;
	
	
	return 0;
}