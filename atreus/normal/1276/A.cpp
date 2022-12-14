#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t --){
		string s;
		cin >> s;
		int n = s.size();
		int a = 0;
		for (int i = 0; i < n - 2; i++)
			if (s.substr(i, 3) == "one" or s.substr(i, 3) == "two")
				a ++;
		for (int i = 0; i < n - 4; i++)
			if (s.substr(i, 5) == "twone")
				a --;
		cout << a << endl;
		for (int i = 0; i < n; i++){
			if (i + 3 > n){
				continue;
			}
			if (s.substr(i, 3) == "one"){
				cout << i + 2 << " ";
				i += 2;
				continue;
			}
			if (s.substr(i, 3) == "two"){
				if (i < n - 4 and s.substr(i, 5) == "twone"){
					cout << i + 3 << " ";
					i += 4;
					continue;
				}
				cout << i + 2 << " ";
				i += 2;
			}
		}
		cout << endl;
	}
}