#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 3000 + 10;
const int mod = 998244353;

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<pair<int,int>> p;
	p.push_back({1, 1});
	for (int i = 2; i <= 2*n+1; i += 2)
		p.push_back({i, 2});
	p.push_back({2*n+1, 1});
	for (int i = 2*n; i >= 2; i -= 2)
		p.push_back({i, 0});
	int sz = (int)p.size();
	for (int i = 0; i < sz; i += 2){
		if (p[i].second == 2 and p[i+1].second == 2){
			int x = p[i].first;
			p.push_back({x, 3});
			p.push_back({x+1, 3});
			p.push_back({x+2, 3});
		}
		else if (p[i].second == 0 and p[i+1].second == 0){
			int x = p[i].first;
			p.push_back({x, -1});
			p.push_back({x-1, -1});
			p.push_back({x-2, -1});
		}
	}
	p.push_back({1, 2});
	if (n & 1)
		p.push_back({2*n+1, 0});
	else
		p.push_back({2*n+1, 2});
	for (int i = 2; i <= 2*n; i ++)
		p.push_back({i, 1});
	cout << p.size() << endl;
	for (auto it : p)
		cout << it.first << " " << it.second << endl;
}