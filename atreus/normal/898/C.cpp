#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <fstream>
#define F first
#define S second
#define PB push_back

using namespace std;

typedef long long ll;
const int maxn = 1e5 + 100;
string s[maxn];
map <string, vector <string> > mp;
map <string, bool> mark, mark1;

bool issuffix (string a, string b){
	if (a.size() < b.size())
		return false;
	int cnt = b.size();
	if (a.substr(a.size() - cnt) == b)
		return true;
	return 0;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> s[i];
		int k;
		cin >> k;
		for (int j = 0; j < k; j++){
			string a;
			cin >> a;
			mp[s[i]].push_back(a);
		}
	}
	int qp = 0;
	for (int i = 0; i < n; i++){
		if (mark[s[i]])
			continue;
		mark[s[i]] = 1;
		qp ++;
		string a = s[i];
		sort (mp[a].begin(), mp[a].end());
		for (int j = 0; j < mp[a].size(); j++){
			for (int k = 0; k < mp[a].size(); k++){
				if (j == k)
					continue;
				if (issuffix(mp[a][k], mp[a][j])){
					mp[a][j] = 'F';
					break;
				}
			}
		}
	}
	cout << qp << endl;
	for (int i = 0; i < n; i++){
		if (mark1[s[i]])
			continue;
		mark1[s[i]] = 1;
		for (int j = 0; j < mp[s[i]].size(); j++){
			if (mp[s[i]][j] == "F"){
				mp[s[i]].erase(mp[s[i]].begin() + j);
				j --;
			}
		}
		cout << s[i] << " " << mp[s[i]].size() << " ";
		for (int j = 0; j < mp[s[i]].size(); j++)
			cout << mp[s[i]][j] << " ";
		cout << endl;
	}

}