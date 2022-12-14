#include <iostream>

using namespace std;

int main (){
	int n, p = 0, q = 0;
	cin >> n;
	for (int i = 1; i <= n; i++){
		string a, b;
		cin >> a >> b;
		if (b == "hard")
			p ++;
		else
			q ++;
	}
	if (p < q)
		swap (p, q);
	for (int i = 1; i <= n; i++){
		if ((i * i + 1) / 2 >= p and (i * i) / 2 >= q)
			return cout << i << endl, 0;
	}
}