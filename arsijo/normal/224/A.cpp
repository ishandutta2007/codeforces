//============================================================================
// Author      : arsijo
// made in Ukraine
//============================================================================

#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	int x, y, z;
	cin >> x >> y >> z;
	int h, l, w;
	h = 0;
	l = 0;
	w = 0;
	for(int i = 1; i <= x; i++){
		if(x % i == 0){
			int a = x / i;
			if(y % a == 0){
				int b = y / a;
				if (z % b == 0){
					if (z / b == i){
						h = a;
						l = b;
						w = i;
						break;
					}
				}
			}else if(z % a == 0){
				int b = z / a;
				if (y % b == 0){
					if (y / b == i){
						h = a;
						l = b;
						w = i;
						break;
					}
				}
			}
		}
	}
	cout << (h * 4) + (l * 4) + (w * 4);
}