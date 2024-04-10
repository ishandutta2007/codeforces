//============================================================================
// Name        :
// Author      : arsijo
// Version     :
// Copyright   :
// Description :
// made in Ukraine
//============================================================================

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	long a, b, c, n, g;
	a = 0;
	b = 0;
	c = 0;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> g;
		//cout << g << " " << a << " " << b << " " << c << endl;
		if (g == 25){
			a++;
		}else if (g == 50){
			if (a > 0){
				a--;
			}else{
				cout << "NO";
				return 0;
			}
			b++;
		}else{
			if (a >= 1 && b >= 1){
				a--;
				b--;
			}else if (a >= 3){
				a -= 3;
			}else{
				cout << "NO";
				return 0;
			}
			c++;
		}
	}
	cout << "YES";
	return 0;
}