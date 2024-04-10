#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main (){
	ios_base::sync_with_stdio(false);
	long long a, b, c;
	cin >> a >> b >> c;
	a *= 10;
	for (int i = 1; i <= 100000 + 500; i++){
		int yek = a / b;
		if (yek == c)
			return cout << i << endl, 0;
		a %= b;
		a *= 10;
	}
	cout << -1 << endl;
}