#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	int a[n], pref[n];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		pref[i] = a[i];
		if(i)
			pref[i] += pref[i - 1];
	}
	vector<int> last(n, -1);
	for(int i = 0; i < n; i++)
		if(pref[i] != 0)
			last[i] = i + 1;
		else
			for(int j = 0; j < i; j++)
				if(pref[j] != 0 && pref[i] - pref[j] != 0)
					last[i] = i - j;
	if(last[n - 1] == -1)
		return cout << "NO", 0;
	cout << "YES\n";
	vector<int> p;
	int i = n - 1;
	while(i != -1) {
		p.push_back(i);
		i -= last[i];
	}
	cout << p.size() << "\n";
	p.push_back(-1);
	for(int i = p.size() - 2; i >= 0; i--)
		cout << p[i + 1] + 2 << ' ' << p[i] + 1 << "\n";
}