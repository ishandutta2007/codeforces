#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> m;

int main() {
	ios_base::sync_with_stdio(false);
	int nb;
	cin >> nb;
	
	int mini = 1000 * 1000 * 1000;
	int maxi = 0;
	
	for(int i = 0;i < nb;i++) {
		int a, b;
		cin >> a >> b;
		m.push_back({a, b});
		
		mini = min(mini, a);
		maxi = max(maxi, b);
	}
	
	for(int i = 0;i < nb;i++) {
		if(mini == m[i].first && maxi == m[i].second) {
			cout << i + 1 << endl;
			return 0;
		}
	}
	
	cout << -1 << endl;
}