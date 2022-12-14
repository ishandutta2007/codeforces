#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
const int maxn = 1e5 + 10;

int nex[maxn], last[maxn];
vector<int> v[2][2];

int main(){
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	int n = s.size(), answer = 0;
	for (int i = 1; i <= n; i++){
		int k = (s[i - 1] == 'L');
		if (!v[k][k].empty()){
			int u = v[k][k].back();
			v[k][k].pop_back();
			nex[last[u]] = i;
			last[u] = i;
			v[k][1^k].push_back(u);
		}
		else if (!v[1^k][k].empty()){
			int u = v[1^k][k].back();
			v[1^k][k].pop_back();
			nex[last[u]] = i;
			last[u] = i;
			v[1^k][1^k].push_back(u);
		}
		else{
			last[i] = i;
			v[k][1^k].push_back(i);
			answer ++;
		}
		nex[i] = -1;
	}
	cout << answer - 1 << endl;
	int k = 0;
	if (v[k][1^k].size() < v[1^k][k].size())
		k = 1;
	while (!v[k][k].empty()){
		int u = v[k][k].back();
		v[k][k].pop_back();
		while (u != -1){
			cout << u << " ";
			u = nex[u];
		}
	}
	if (!v[k][1^k].empty()){
		int u = v[k][1^k].back();
		v[k][1^k].pop_back();
		while (u != -1){
			cout << u << " ";
			u = nex[u];
		}
	}
	while (!v[1^k][1^k].empty()){
		int u = v[1^k][1^k].back();
		v[1^k][1^k].pop_back();
		while (u != -1){
			cout << u << " ";
			u = nex[u];
		}
	}
	k ^= 1;
	while (!v[k][1^k].empty()){
		int u = v[k][k^1].back();
		v[k][k^1].pop_back();
		while (u != -1){
			cout << u << " ";
			u = nex[u];
		}
		k ^= 1;
	}
	cout << endl;
}