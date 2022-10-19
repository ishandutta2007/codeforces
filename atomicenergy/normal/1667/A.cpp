#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;


int main() {

	int n;
	cin >> n;
	vector<long long> a;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a.push_back(x);
	}
	long long mn = 1000000000000000000;
	for (int i = 0; i < n; i++) {
		long long tot = 0;
		long long cur = 0;
		for (int j = i + 1; j < n; j++) {
			tot += (cur / a[j] + 1);
			cur = a[j] * (cur / a[j] + 1);
		}
		cur = 0;
		for (int j = i - 1; j >=0 ; j--) {
			tot += (cur / a[j] + 1);
			cur = a[j] * (cur / a[j] + 1);
		}
		mn = min(mn, tot);
	}
	cout << mn << endl;

		
	
}