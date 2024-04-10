#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

const int maxn = 1 + 100;
bool mark[maxn];
vector <int> v[maxn];


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--){
		int n, p;
		cin >> n >> p;
		for (int i = 0; i < maxn; i++)
			v[i].clear();
		for (int i = 1; i < 3; i++){
			for (int j = 1; j <= n; j++){
				int k = (i + j) % n;
				if (k == 0)
					k = n;
				v[j].push_back(k);
			}
		}
		for (int i = 3; i < n; i++){
			if (p == 0)
				break;
			for (int j = 1; j <= n; j++){
				if (p == 0)
					break;
				int k = (i + j) % n;
				if (k == 0)
					k = n;
				v[j].push_back(k);
				p --;
			}
		}
		for (int i = 1; i <= n; i++)
			for (int j = 0; j < v[i].size(); j++)
				cout << i << " " << v[i][j] << '\n';
	}
}