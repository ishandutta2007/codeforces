#include <bits/stdc++.h>
using namespace std;
 
const int MAX1 = 1e2+10;
 
int n, m, q;
 
int main(){
	cin >> q;
	while (q--){
		cin >> m >> n;
		if (m == 1)	cout << 0;
		if (m == 2)	cout << n;
		if (m > 2)	cout << n*2;
		cout << '\n';
	}
	return 0;
}