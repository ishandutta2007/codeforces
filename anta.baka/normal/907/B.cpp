#include <bits/stdc++.h>
using namespace std;

int main() {
	char a[9][9];
	for(int i = 0; i < 9; i++)
		for(int j = 0; j < 9; j++)
			cin >> a[i][j];
	int i1, j1;
	cin >> i1 >> j1;
	i1--; j1--;
	i1 %= 3;
	j1 %= 3;
	bool any = false;
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			if(a[i1 * 3 + i][j1 * 3 + j] == '.') {
				any = true;
				a[i1 * 3 + i][j1 * 3 + j] = '!';
			}
	if(!any)
		for(int i = 0; i < 9; i++)
			for(int j = 0; j < 9; j++)
				if(a[i][j] == '.')
					a[i][j] = '!';
	for(int i = 0; i < 9; i++, cout << endl) {
		for(int j = 0; j < 9; j++) {
			cout << a[i][j];
			if(j % 3 == 2) cout << ' ';
		}
		if(i % 3 == 2) cout << endl;
	}
}