#include <iostream>
#include <string>

using namespace std;
int check(int **bored, int x1, int y1, int x2, int y2, int x3, int y3) {
	return bored[x1][y1] + bored[x2][y2] + bored[x3][y3];
}
int main(){
	int **bored= new int*[4];
	for (int i = 0; i < 4; i++) {
		bored[i]= new int[4];
		string line;
		cin >> line;
		for (int j = 0; j < 4; j++) {
			if (line[j] == 'x') {
				bored[i][j] = 1;
			} else if (line[j] == 'o') {
				bored[i][j] = -1;
			} else {
				bored[i][j] = 0;
			}
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 2; j++) {
			if (check(bored, i, j, i, j + 1, i,j + 2) == 2) {
				cout << "Yes\n";
				return 0;
			}
			if (check(bored, j, i, j + 1, i, j + 2,i) == 2) {
				cout << "Yes\n";
				return 0;
			}
		}
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			if (check(bored, i, j, i + 1, j + 1, i + 2, j + 2) == 2) {
				cout << "Yes\n";
				return 0;
			}
			if (check(bored, j, i + 2, j + 1, i + 1, j + 2, i) == 2) {
				cout << "Yes\n";
				return 0;
			}
		}
	}
	cout << "NO\n";
	return 0;
}