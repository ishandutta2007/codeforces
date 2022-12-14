#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#define F first
#define S second
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
const int maxn = 1e5 + 100;
string s[maxn];
unordered_set <string> visited;
unordered_map <string, vector <string> > v;
unordered_map <string, ll> win, lose;

void dfs (string s){
	if (v[s].empty()){
		win[s] = 0;
		lose[s] = 1;
		return;
	}
	for (int i = 0; i < v[s].size(); i++){
		dfs (v[s][i]);
		if (win[v[s][i]] == 0)
			win[s] = 1;
		if (lose[v[s][i]] == 0)
			lose[s] = 1;
	}
}

void ins (string root, string s, int pos){
	if (pos >= s.size())
		return;
	if (visited.find(root + s[pos]) != visited.end()){
		ins (root + s[pos], s, pos + 1);
		return;
	}
	v[root].PB(root + s[pos]);
	visited.insert(root + s[pos]);
	ins (root + s[pos], s, pos + 1);
	return;
}

int main(){
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	for (int i = 0; i < n; i++){
		ins ("", s[i], 0);
	}
	dfs ("");
	if (win[""] == 0)
		return cout << "Second" << endl, 0;
	if (lose[""] == 1)
		return cout << "First" << endl, 0;
	if (k % 2 == 1)
		return cout << "First" << endl, 0;
	cout << "Second" << endl;
}