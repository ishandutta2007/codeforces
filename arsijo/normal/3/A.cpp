/*
 *      Author: arsijo;
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
	//freopen("c.in", "r", stdin); freopen("c.out", "w", stdout);
	string s;
	cin >> s;
	int x1 = s[0] - 'a';
	int y1 = s[1] - '0';
	cin >> s;
	int x2 = s[0] - 'a';
	int y2 = s[1] - '0';
	cout << max(abs(x1 - x2), abs(y1 - y2)) << endl;
	while (x1 != x2 || y1 != y2){
		if (x1 == x2){
			if (y1 > y2){
				cout << "D";
				y1--;
			}else{
				cout << "U";
				y1++;
			}
		}else if (y1 == y2){
			if (x1 > x2){
				cout << "L";
				x1--;
			}else{
				cout << "R";
				x1++;
			}
		}else{
			char c1, c2;
			if (x1 > x2){
				c1 = 'L';
				x1--;
			}else{
				c1 = 'R';
				x1++;
			}
			if (y1 > y2){
				c2 = 'D';
				y1--;
			}else{
				c2 = 'U';
				y1++;
			}
			cout << c1 << c2;
		}
		cout << endl;
	}
}