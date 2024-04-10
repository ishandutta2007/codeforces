#include <bits/stdc++.h>

using namespace std;

char a[10][10];

bool win() {
	for(int i = 0; i < 10; i++)
		for(int j = 0; j < 10; j++) {
			if(i >= 4) {
				bool ok = true;
				for(int k = 0; k < 5; k++)
					ok &= (a[i - k][j] == 'X');
				if(ok) return true;
			}
			if(j >= 4) {
				bool ok = true;
				for(int k = 0; k < 5; k++)
					ok &= (a[i][j - k] == 'X');
				if(ok) return true;
			}
			if(i >= 4 && j >= 4) {
				bool ok = true;
				for(int k = 0; k < 5; k++)
					ok &= (a[i - k][j - k] == 'X');
				if(ok) return true;
			}
			if(i >= 4 && j <= 5) {
				bool ok = true;
				for(int k = 0; k < 5; k++)
					ok &= (a[i - k][j + k] == 'X');
				if(ok) return true;
			}
		}
	return false;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	for(int i = 0; i < 10; i++)
		for(int j = 0; j < 10; j++)
			cin >> a[i][j];
	for(int i = 0; i < 10; i++)
		for(int j = 0; j < 10; j++)
			if(a[i][j] == '.') {
				a[i][j] = 'X';
				if(win()) return cout << "YES", 0;
				a[i][j] = '.';
			}
	cout << "NO";
}