#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

vector<bool> found;
vector< vector<int> > v;
map<pair<int, int>, bool> m;
vector<int> a;
vector<int> b;
vector<int> c;

int dfs(int n, int f){
	int cur = -1;
	if(found[n]){
		if(m[make_pair(f, n)]) return -1;
		return n;	
	} 
	found[n] = true;
	for(int i=0; i<v[n].size(); i++){
		if(v[n][i] == f) continue;
		
		int z = dfs(v[n][i], n);
		if(z==-1) continue;
		if(cur == -1) {
			cur = z;
			continue;
		}
		a.push_back(cur);
		b.push_back(n);
		c.push_back(z);
		m[make_pair(cur, n)] = true;
		m[make_pair(n, z)] = true;
		m[make_pair(n, cur)] = true;
		m[make_pair(z, n)] = true;
		cur = -1;
	}
	if(cur!=-1){
		if(f!=-1){
			a.push_back(cur);
			b.push_back(n);
			c.push_back(f);
			m[make_pair(cur, n)] = true;
			m[make_pair(n, f)] = true;
			m[make_pair(n, cur)] = true;
			m[make_pair(f, n)] = true;
		}
		return -1;
	}
	return n;
}

int main() {
	int n, m;
	cin >> n >> m;
	
	for(int i=0; i<n; i++){
		vector<int> u;
		v.push_back(u);	
	}
	for(int i=0; i<m; i++){
		int x, y;
		cin >> x >> y;
		v[x-1].push_back(y-1);
		v[y-1].push_back(x-1);
	}
	for(int i=0; i<n; i++){
		found.push_back(false);
	}
	for(int i=0; i<n; i++){
		if(!found[i]) dfs(i, -1);
	}
	cout << a.size() << endl;
	for(int i=0; i<a.size(); i++){
		cout << a[i]+1 << " " << b[i]+1 << " " << c[i]+1 << endl;
	}
}