/*
 *      Author: arsijo;
 */

#include <bits/stdc++.h>
using namespace std;

string getAns(int a, int b, int c){
	string w = "Impossible";
	if ((b + c - a) % 2 == 1)
		return w;

	int y = (b + c - a) / 2;
	int x = b - y;
	int z = c - y;
	if(x < 0 || y < 0 || z < 0)
		return w;

	cout << x << " " << y << " " << z << endl;
	return "";
}

int main() {

	int a, b, c;
	cin >> a >> b >> c;
	cout << getAns(a, b, c);
}