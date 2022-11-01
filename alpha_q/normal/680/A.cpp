#include <bits/stdc++.h>

using namespace std;

int a[10], sum = 0;
map <int, int> M;
set <int> two, three;

int main (int argc, char const *argv[]) {
	for (int i = 0; i < 5; ++i) cin >> a[i], M[a[i]]++, sum += a[i];
	for (auto it : M) {
		if (it.second >= 3) three.insert(it.first);
		else if (it.second >= 2) two.insert(it.first);
	}

	int away = 0;
	if (!two.empty()) away = max(away, 2 * (*(--two.end())));
	if (!three.empty()) away = max(away, 3 * (*(--three.end())));

	cout << sum - away << endl;
	return 0;
}