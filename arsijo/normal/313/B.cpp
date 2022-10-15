//============================================================================
// Author      : arsijo
// made in Ukraine
//============================================================================

#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	string s;
	cin >> s;
	int ar [s.length()];
	ar[0] = 0;
	int len = s.length();
	for(int i = 1; i < len; i++){
		ar[i] = ar[i-1];
		if (s[i] == s[i-1]){
			ar[i]++;
		}
	}
	int a, l, r;
	cin >> a;
	for(int i = 0; i < a; i++){
		cin >> l >> r;
		cout << ar[r-1] - ar[l-1] << " ";
	}

}