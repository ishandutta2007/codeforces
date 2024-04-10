#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

vector<int> par;
vector<vector<int> > G;

void dfs(int n, int p){
	par[n] = p;
	for(int i : G[n]){
		if(i==p) continue;
		dfs(i, n);
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		par.clear();
		
		G.clear();
		vector<int> tmp;
		for(int i=0; i<n; i++){
			par.push_back(0);
			G.push_back(tmp);
		}
		for(int i=1; i<n; i++){
			int x, y;
			cin >> x >> y;
			x--;
			y--;
			G[x].push_back(y);
			G[y].push_back(x);	
		}
		vector<int> s;
		vector<int> t;
		vector<bool> in_s(n, false);
		vector<bool> in_t(n, false);
		int k;
		cin >> k;
		for(int i=0; i<k; i++){
			int x;
			cin >> x;
			x--;
			in_s[x] = true;
			s.push_back(x);
		}
		cin >> k;
		for(int i=0; i<k; i++){
			int x;
			cin >> x;
			x--;
			in_t[x] = true;
			t.push_back(x);
		}
		cout << "A " << s[0]+1 << endl;
		fflush(stdout);
		int x;
		cin >> x;
		x--;
		if(in_t[x]){
			cout << "C " << s[0]+1 << endl;
			fflush(stdout);
			continue;
		}
		dfs(s[0], -1);
		cout << "B " << t[0]+1 << endl;
		fflush(stdout);

		cin >> x;
		x--;
		if(in_s[x]){
			cout << "C " << x+1 << endl;
			fflush(stdout);
			continue;
		}
		
		while(!in_s[x]){
			x = par[x];
		}
		
		cout << "A " << x+1 << endl;
		fflush(stdout);
		int y;
		cin >> y;
		y--;
		if(in_t[y]){
			cout << "C " << x+1 << endl;
			fflush(stdout);
			continue;
		}
		else{
			cout << "C " << -1 << endl;
			fflush(stdout);
			continue;
		}
	}
}