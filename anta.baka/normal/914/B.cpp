#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> cnt(100000, 0);
	for(int i = 0; i < n; i++) {
		int x; cin >> x;
		cnt[x - 1]++;
	}
	for(int i = 0; i < 100000; i++)
		if(cnt[i] % 2 == 1)
			return cout << "Conan", 0;
	cout << "Agasa";
}