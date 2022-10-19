#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	int i;
	for (i = 0; i < t; i++) {
		int n, m;
		cin >> n >> m;
		string s;
		cin >> s;
		vector<int> p(m);
		int j;
		vector<int> pr(n);
		for (j = 0; j < m; j++) {
			cin >> p[j];
		}
		for(j = 0; j < n; j++)
			pr[j] = 0;
		for (j = 0; j < m; j++) {
			pr[p[j] - 1] += 1;
		}
		for (j = n - 2; j >= 0; j--) 
			pr[j] = pr[j] + pr[j + 1];
		vector<int> b(26);
		for (j = 0; j < 26; j++)
			b[j] = 0;
		for (j = 0; j < n; j++)
			b[int(s[j] - 'a')] = b[int(s[j] - 'a')]+pr[j]+1;
		for (j = 0; j < 26; j++)
			cout << b[j] << " ";
		cout << endl;
	}
	return 0;
}