#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 100 * 1000 + 7, SQ = 595, inf = 1000 * 1000 * 1000 + 5;

vector <int> vec[N];
vector <int> al;
long long f[N][7];

int main() {
	int n;
	cin >> n;
	for (int ii = 0; ii < n; ii++) {
	//	cout << "72 " << vec[0].size() << endl;
		string qt;
		cin >> qt;
		if (qt == "add") {
			int x;
			cin >> x;
			int t = 0;
			while (vec[t + 1].size() && vec[t + 1][0] <= x) {
				t++;
			}
			int k = lower_bound(vec[t].begin(), vec[t].end(), x) - vec[t].begin();
			vec[t].insert(vec[t].begin() + k, x);
			for (int j = 0; j < 5; j++) {
				f[t][j] = 0; 
			}
			for (int j = 0; j < vec[t].size(); j++) {
				f[t][j % 5] += vec[t][j];
			}
		}
		if (qt == "del") {
			int x;
			cin >> x;
			int t = 0;
			while (vec[t + 1].size() && vec[t + 1][0] <= x) {
				t++;
			}
			int k = lower_bound(vec[t].begin(), vec[t].end(), x) - vec[t].begin();
		//	cout << "71 " << k << " " << vec[t][k] << " " << vec[t][1] << endl;
			vec[t].erase(vec[t].begin() + k);
			for (int j = 0; j < 5; j++) {
				f[t][j] = 0; 
			}
			for (int j = 0; j < vec[t].size(); j++) {
				f[t][j % 5] += vec[t][j];
			}					
		}
		if (qt == "sum") {
			int t = 0;
			long long ans = 0;
			for (int i = 0; i < SQ; i++) {
				ans += f[i][(N - t) % 5];
				t += vec[i].size();
			}
			cout << ans << endl;
		}
		
		
		if (ii % SQ == 0) {
			al.clear();
			for (int i = 0; i < SQ; i++) {
				for (auto x : vec[i]) {
					al.push_back(x);
				}
				vec[i].clear();
				for (int j = 0; j < 5; j++) {
					f[i][j] = 0;
				}
			}
			for (int i = 0; i < al.size(); i++) {
				vec[i / SQ].push_back(al[i]);
				f[i / SQ][i % 5] += al[i];
			}
		}
	}
	
	
	return 0;
}