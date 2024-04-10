//============================================================================
// Author      : arsijo
// made in Ukraine
//============================================================================

#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	int n;
	cin >> n;
	char ch, ch2;
	for (int i = 0; i < n; i++){
		string s;
		cin >> s;
		if (i == 0){
			ch = s[0];
			ch2 = s[1];
			if (ch == ch2){
				cout << "NO";
				return 0;
			}
		}

		for(int j = 0; j < n; j++){
			if (i == j || i + j + 1 == n){
				if (s[j] != ch){
					cout << "NO";
					return 0;
				}
			}else{
				if (s[j] != ch2){
					cout << "NO";
					return 0;
				}
			}
		}
	}
	cout << "YES";
}