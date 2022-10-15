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
	string s;
	cin >> s;
	int a = 0;
	for(int i = 0; i < (n / 2); i++){
		if (s[i] != '4' && s[i] != '7'){
			cout << "NO";
			return 0;
		}
		a += s[i];
	}
	int b = 0;
	for(int i = (n / 2); i < n; i++){
		if (s[i] != '4' && s[i] != '7'){
					cout << "NO";
					return 0;
		}
		b+= s[i];
	}
	if (a == b){
		cout << "YES";
	}else{
		cout << "NO";
	}

}