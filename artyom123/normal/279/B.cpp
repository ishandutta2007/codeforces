#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
	int n, t;
	cin >> n >> t;
	vector <int> a(n);
	for ( int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int max1 = 0;
	
	int left = -1;
	
	for ( int i = 0; i < n; i++) {
		if ( a[i] <= t) {
			left = i;
			break;
		}
	}
	if ( left == -1) {
		cout << 0;
		return 0;
	}
	max1 = 1;
	int now = 1;
	int sum = a[left];
	for ( int i = left + 1; i < n; i++) {
		if ( now > max1) {
			max1 = now;
		}
		if (a[i] + sum > t ){
			sum += a[i];
			now += 1;
			int minus = 0;
			int k = 0;
			for ( int j = left; j <= i; j++) {
				minus += a[j];
				k += 1;
				if ( sum - minus <= t) {
					left = j + 1;
					now -= k;
					sum -= minus;
					break;
				}
			}
		}
		else {
			now += 1;
			sum += a[i];
			
		}
	}
	if ( now > max1) {
		max1 = now;
	}
	cout << max1;
	
	return 0;
}