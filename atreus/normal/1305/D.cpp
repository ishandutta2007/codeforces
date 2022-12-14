#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
const int mod = 1e9 + 7;
const int maxn = 2e5 + 10;

int d[maxn];
vector<int> t[maxn];

int ask(int v, int u){
	cout << "? " << v << " " << u << endl;
	int ret;
	cin >> ret;
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++){
		int v, u;
		cin >> v >> u;
		t[v].push_back(u);
		t[u].push_back(v);
		d[v] ++, d[u] ++;
	}
	set<pair<int,int> > s;
	for (int i = 1; i <= n; i++)
		s.insert({d[i], i});
	while (s.size() > 1){
		int v = (*s.begin()).second;
		s.erase(s.begin());
		int u = (*s.begin()).second;
		s.erase(s.begin());
		int w = ask(v, u);
		if (w == u or w == v){
			cout << "! " << w << endl;
			return 0;
		}
		d[v] = d[u] = 0;
		for (auto x : t[v]){
			if (d[x] > 0){
				s.erase({d[x], x});
				d[x] --;
				s.insert({d[x], x});
			}
		}
		for (auto x : t[u]){
			if (d[x] > 0){
				s.erase({d[x], x});
				d[x] --;
				s.insert({d[x], x});
			}
		}
	}
	int v = (*s.begin()).second;
	cout << "! " << v << endl;
}