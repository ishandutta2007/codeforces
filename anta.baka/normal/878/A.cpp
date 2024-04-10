#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, b[500000], to[2][10], door, doand = 1023, doxor;
char a[500000];

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}
	for(int i = 0; i < 10; i++)
		for(int j = 0; j < 2; j++) {
			int x = (j == 0 ? 0 : (1 << i));
			for(int z = 0; z < n; z++)
				if(a[z] == '|') x |= b[z];
				else if(a[z] == '&') x &= b[z];
				else x ^= b[z];
			to[j][i] = ((x & (1 << i)) != 0);
		}
	for(int i = 0; i < 10; i++)
		if(to[0][i] == 1 && to[1][i] == 1) door += (1 << i);
		else if(to[0][i] == 0 && to[1][i] == 0) doand -= (1 << i);
		else if(to[0][i] == 1 && to[1][i] == 0) doxor += (1 << i);
	cout << (door != 0) + (doand != 1023) + (doxor != 0) << '\n';
	if(door != 0) cout << "| " << door << '\n';
	if(doand != 1023) cout << "& " << doand << '\n';
	if(doxor != 0) cout << "^ " << doxor;
}