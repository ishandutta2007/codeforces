#include <iostream>

using namespace std;

int main (){
	bool b = 0;
	int n;
	cin >> n;
	int m = 0;
	cin >> m;
	for (int i = 1; i < n; i++){
		int v;
		cin >> v;
		if (abs (v - m) >= 2)
			b = 1;
		m = v;
	}
	if (b)
		cout << "NO" << endl;
	else
		cout << "YES" << endl;
}