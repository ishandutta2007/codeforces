
#include <iostream>

bool win = false;

bool isWinning(char x, char y, char z) {
	if(win == true)
		return true;
	
	if(
		x == '.' && y == 'x' && z == 'x' ||
		x == 'x' && y == '.' && z == 'x' ||
		x == 'x' && y == 'x' && z == '.') {
			std::cout << "YES";
			return win = true;
		}
	
	return false;
}

bool checkDiag(char a, char b, char c, char d) {
	return isWinning(a, b, c) || isWinning(b, c, d);
}

int main() {
	char t[4][4];
	for(int i = 0; i < 4; ++i) {
		std::string s;
		std::cin >> s;
		for(int j = 0; j < 4; ++j) {
			t[i][j] = s[j];
		}
	}
	
	for(int i = 0; i < 4; ++i)
		for(int j = 0; j < 2; ++j)
			if(isWinning(t[i][j], t[i][j + 1], t[i][j + 2]) ||
				isWinning(t[j][i], t[j + 1][i], t[j + 2][i]))
					return 0;
	
	if(checkDiag(t[0][0], t[1][1], t[2][2], t[3][3]) || isWinning(t[1][0], t[2][1], t[3][2]) || isWinning(t[0][1], t[1][2], t[2][3]))
		return 0;
	if(checkDiag(t[0][3-0], t[1][3-1], t[2][3-2], t[3][3-3]) || isWinning(t[1][3-0], t[2][3-1], t[3][3-2]) || isWinning(t[0][3-1], t[1][3-2], t[2][3-3]))
		return 0;

	std::cout << "No";
	return 0;
}