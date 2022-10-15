/*
 *      Author: arsijo;
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
	//freopen("c.in", "r", stdin); freopen("c.out", "w", stdout);
	map<string, int> m;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		if (m.count(s) == 0){
			cout << "OK" << endl;
			m.insert(pair<string, int> (s, 1));
		}else{
			cout << s << m[s] << endl;
			m[s]++;
		}
	}
}