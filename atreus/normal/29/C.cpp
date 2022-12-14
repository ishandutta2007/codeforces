#include <iostream>
#include <map>
#include <vector>

using namespace std;

map <int, vector <int> > mp;
map <int, bool> mark, moork;

int k, inx;

void dfs(int x, int l){
	mark[x] = true;
	if (l >= k){
		k = l;
		inx = x;
	}
	for (int i = 0; i < mp[x].size(); i++)
		if (!mark[mp[x][i]])
			dfs(mp[x][i], l + 1);
}

int main(){
	int n, id = 0;
	cin >> n;
	for (int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		mp[a].push_back(b);
		mp[b].push_back(a);
		id = a;
	}
	dfs(id, 0);
	int k = inx;
	while (true){
		bool cur = false;
		moork[k] = true;
		cout << k << " ";
		for (int i = 0; i < mp[k].size(); i++)
			if (!moork[mp[k][i]]){
				k = mp[k][i];
				cur = true;
				break;
			}
		if (cur == false)
			break;
	}
}