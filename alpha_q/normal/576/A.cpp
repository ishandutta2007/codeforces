#include <bits/stdc++.h>

using namespace std;

bool IsPrime (int x) {
	if (x == 1) return false;
	else if (x == 2) return true;
	else if (x % 2 == 0) return false;
	
	for (int i = 3; i * i <= x; i += 2)
		if (x % i == 0) return false;
	
	return true;
}

int main() {
	int n; cin >> n;
	vector <int> V;
	for (int i = 2; i <= n; i++) 
		if (IsPrime(i)) {
			int p = i;
			while (p <= n) {
				V.push_back(p);
				p *= i;
			}
		}
	int k = V.size();
	
	cout << k << endl;
	for (int i = 0; i < k; i++) cout << V[i] << " ";
	cout << endl;
	return 0;
}