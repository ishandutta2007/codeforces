#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int k, a, b, l;
	string st;
	scanf("%d %d %d\n", &k, &a, &b);
	cin >> st;
	l = st.length();
	int x = l / k;
	int i, g, z = 0;
	int c = l;
	vector<string> aa(k);
	for (i = 0; i < k; i++) {
		if (x < a || x > b) {
			cout << "No solution";
			return 0;
		}	
		for (g = 0; g < x; g++) {
			aa[i] += st[z];
			z++;
		}
		//cout << endl;
		l -= x;
		if (i != k-1)
		x = l / (k - 1 - i);
	}
	for (i = 0; i < k; i++) {
		cout << aa[i] << endl;
	}


	return 0;
}//ahlbgk