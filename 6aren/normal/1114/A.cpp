#include <bits/stdc++.h>

using namespace std;


int main() {
	//freopen("in", "r", stdin);
	int x, y, z, a, b, c;
	cin >> x >> y >> z >> a >> b >> c;
	if (x > a) {
		return cout << "NO", 0;
	} 
	a -= x;
	if (y > a + b) {
		return cout << "NO", 0;
	}
	a -= y;
	if (z > a + b + c) {
		return cout << "NO", 0;
	}
	cout << "YES";
}
/* 
g++ online.cpp -o online.exe
*/