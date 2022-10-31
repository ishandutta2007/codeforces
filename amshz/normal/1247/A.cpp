# include <bits/stdc++.h>

using namespace std;

//const int xn = 

int main(){
	int a, b;
	cin >> a >> b;
	if (a == b){
		cout << a;
		cout << 1;
		cout << ' ';
		cout << b << 2;
		return 0;
	}
	if (a == b-1){
		cout << a << 9 << ' ' << b << 0;
		return 0;
	}
	if (a == 9 and b == 1){
		cout << a << ' ' << 10;
		return 0;
	}
	cout << -1 << endl;
	return 0;
}