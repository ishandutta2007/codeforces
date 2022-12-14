#include <bits/stdc++.h>

using namespace std;

int main (){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		int a;
		cin >> a;
		if (a == 1 || a == 2 || a == 4 || a == 5 || a == 8 || a == 11)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
}