//============================================================================
// Author      : arsijo
// made in Ukraine
//============================================================================

#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	int x, y;
	cin >> x >> y;
	int a = 0;
	int b = 0;
	int c = 0;
	for (int i = 1; i <= 6; i++){
		int q = abs(x - i);
		int w = abs(y - i);
		if (q < w){
			a++;
		}else if (w < q){
			c++;
		}else{
			b++;
		}
	}

	cout << a << " " << b << " " << c;

}