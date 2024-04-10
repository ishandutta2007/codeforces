#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e3 + 100;
map <string, vector <string> > v;
map <string, bool> mark;
int k;

string low (string s){
	for (int i = 0; i < s.size(); i++){
		if (int(s[i]) >= 65 and int(s[i]) <= 90){
			int a = int(s[i]);
			a += 32;
			s[i] = char(a);
		}
	}
	return s;
}

void dfs (string u, int h){
	mark[u] = 1;
	k = max (k, h);
	for (int i = 0; i < v[u].size(); i++)
		if (!mark[v[u][i]])
			dfs (v[u][i], h + 1);
}

int main (){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		string a, b, c;
		cin >> a >> b >> c;
		a = low(a);
		c = low(c);
		v[c].push_back(a);
	}
	dfs ("polycarp", 1);
	cout << k << endl;
}