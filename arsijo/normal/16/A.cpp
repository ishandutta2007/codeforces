/*
 *      Author: arsijo;
 *      made in Ukraine;
 */

#include <bits/stdc++.h>
using namespace std;

int main(){

	int n, m;
	cin >> n >> m;
	string s[n];
	for(int i = 0; i < n; i++)
		cin >> s[i];
	for(int i = 0; i < n; i++){
		for(int j = 1; j < m; j++){
			if (s[i][j] != s[i][j-1]){
				cout << "NO";
				return 0;
			}
		}
	}
	for(int i = 1; i < n; i++){
		if (s[i][0] == s[i-1][0]){
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";

}