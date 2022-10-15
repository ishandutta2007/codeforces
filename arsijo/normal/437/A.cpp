/*
 *      Author: arsijo;
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	string s[4];
	int len[4];
	bool res[4];
	for (int i = 0; i < 4; i++) {
		cin >> s[i];
		len[i] = s[i].length() - 2;
	}
	int ans = 2;
	for (int i = 0; i < 4; i++) {
		bool flag = true;
		for (int j = 0; j < 4; j++) {
			if (i == j)
				continue;
			if (len[i] * 2 > len[j]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			res[i] = true;
			continue;
		}
		flag = true;
		for (int j = 0; j < 4; j++) {
			if (i == j)
				continue;
			if (len[i] < 2 * len[j]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			res[i] = true;
			continue;
		}
	}
	int g = 0;
	for(int i = 0; i < 4; i++)
		if (res[i])
			g++;
	if (g == 1){
		for(int i = 0; i < 4; i++){
			if (res[i]){
				ans = i;
				break;
			}
		}
	}
	char a = ans + 'A';
	cout << a;
}