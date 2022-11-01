#include <bits/stdc++.h>

using namespace std;

int s, m, i, j; 

bool val (int s, int m) {
	return 0 <= s && s <= 9 * m;
}

int main() {
	cin >> m >> s; 
	
	if (!val(s, m) || (s == 0 && m > 1)) {
		cout << "-1 -1\n";
		return 0;
	}
	
	string Min = "";
	string Max = "";
	
	int ss = s;
	for (i = 0; i < m; i++)
		for (j = 0; j <= 9; j++)
			if ((i > 0 || j > 0 || m == 1) && val(s - j, m - i - 1)) {
				Min += (char)(j + '0');
				s -= j;
				break;
			}
	
	for (i = 0; i < m; i++) 
		for (j = 9; j >= 0; j--)
			if ((i > 0 || j > 0 || m == 1) && val(ss - j, m - i - 1)) {
				Max += (char)(j + '0');
				ss -= j;
				break;
			}
	
	cout << Min << " " << Max << endl;
	return 0;
}