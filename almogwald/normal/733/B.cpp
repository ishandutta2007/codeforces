#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
	int n, r_sum = 0, l_sum=0,r_max=0, l_max = 0, r_max_place=0, l_max_place=0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int l, r;
		cin >> l;
		cin >> r;
		r_sum += r;
		l_sum += l;
		if (r_max < r - l) {
			r_max_place = i;
			r_max = r - l;
		}
		if (l_max < l - r) {
			l_max_place = i;
			l_max = l - r;
		}
	}

	if (r_sum + l_max * 2 - l_sum > l_sum + r_max * 2 - r_sum) {
		cout << l_max_place << '\n';
	}
	else {
		cout << r_max_place << '\n';
	}
	//string tmp;
	//cin >> tmp;
	return 0;
}