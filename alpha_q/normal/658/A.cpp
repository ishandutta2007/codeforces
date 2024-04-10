#include <bits/stdc++.h>

using namespace std;

int main() {	
	//freopen("input.txt", "r", stdin);

	int n, c, p[60], t[60];
	int L = 0, R = 0;

	cin >> n >> c;
	for (int i = 1; i <= n; i++) cin >> p[i];
	for (int i = 1; i <= n; i++) cin >> t[i];
	
	int spent = 0;
	for (int i = 1; i <= n; i++) {
		spent += t[i];
		L += max(0, p[i] - c * spent);
	} 

	spent = 0;
	for (int i = n; i >= 1; i--) {
		spent += t[i];
		R += max(0, p[i] - c * spent);
	}

	if (L > R) cout << "Limak\n";
	else if (R > L) cout << "Radewoosh\n";
	else cout << "Tie\n";
    return 0;
}