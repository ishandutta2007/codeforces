//============================================================================
// Author      : arsijo
// made in Ukraine
//============================================================================

#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	int n, a, b, c;
	cin >> n >> a >> b >> c;
	int ans = -1;
	for(int i = 0; i*a <= n; i++){
		for(int j = 0; j*b <= n - i*a; j++){
			int d = n - i*a - j*b;
			if(d >= 0 && d % c == 0){
				int e = (d / c) + i + j;
				if (e > ans){
					ans = e;
				}
			}
		}
	}
	cout << ans;
}