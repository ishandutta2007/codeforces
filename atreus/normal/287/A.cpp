#include <iostream>

using namespace std;

string s[5];

bool f(char a, char b, char c, char d){
	if (a == b and b == c)
		return true;
	if (a == b and b == d)
		return true;
	if (a == c and c == d)
		return true;
	if (b == c and c == d)
		return true;
	return false;
}

int main (){
	for (int i = 0; i < 4; i++)
		cin >> s[i];
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			if (f(s[i][j], s[i][j + 1], s[i + 1][j], s[i + 1][j + 1]))
					return cout << "YES" << endl, 0;
		}
	}
	cout << "NO" << endl;
}