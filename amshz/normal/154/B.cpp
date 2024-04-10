# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef double ld;
typedef pair <int, int> pii;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9 + 7;
const int xn = 1e5 + 10;
const int xm = 1e5 + 10;
const int SQ = 320;
const int sq = 1e3 + 10;
const ll inf = 1e18 + 10;


int n, m;
bool p[xn];
map <int, bool> mp;
vector <int> Primes, adj[xn];
set <int> st[xn];

 
int main(){
	fast_io;
	
	cin >> n >> m;
	
	for (int i = 2; i <= 1e5; i ++){
		if (p[i]) continue;
		adj[i].push_back(i);
		for (int j = i + i; j <= 1e5; j += i){
			p[j] = true;
			adj[j].push_back(i);
		}
		Primes.push_back(i);
	}
	
	while (m --){
		char c;
		int x;
		cin >> c >> x;
		if (c == '+'){
			if (mp[x]){
				cout << "Already on" << endl;
				continue;
			}
			bool flag = true;
			for (int j : adj[x]){
				if (st[j].size() > 0 && flag){
					cout << "Conflict with " << *st[j].begin() << endl;
					flag = false;
				}
			}
			if (flag) {
				cout << "Success" << endl;
				mp[x] = true;
				for (int j : adj[x]) st[j].insert(x);
			}
		}
		else{
			if (!mp[x]){
				cout << "Already off" << endl;
				continue;
			}
			mp[x] = false;
			for (int j : adj[x]) st[j].erase(x);
			cout << "Success" << endl;
		}
	}
	
	
	
	return 0;
}