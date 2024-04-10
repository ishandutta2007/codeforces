#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
	int n,k,* after,* before;
	cin >> n;
	before = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> before[i];
	}
	cin >> k;
	after = new int[k];
	for (int i = 0; i < k; i++) {
		cin >> after[i];
	}
	int * eat_i = new int[n - k];
	char * eat_direction = new char[n - k];
	int m = 0,monsrers_after=0, monsrers_before =0;
	while (monsrers_after < k) {
		int sum = 0;
		int start = monsrers_before;
		int max = 0;
		while (monsrers_before < n && sum < after[monsrers_after]) {
			sum += before[monsrers_before];
			if (max < before[monsrers_before]) {
				max = before[monsrers_before];
			}
			monsrers_before++;
		}
		if (sum != after[monsrers_after]) {
			cout << "NO\n";
			return 0;
		}
		if (start == monsrers_before - 1) {
			monsrers_after++;
			continue;
		}
		bool found = false;
		int pos, toeat_l, toeat_r;
		if (before[start] == max&&before[start + 1] != max) {
			found = true;
			pos = monsrers_after + 1;
			toeat_r = monsrers_before - 1 - start;
			toeat_l = 0;
		} else if (before[monsrers_before-1] == max&&before[monsrers_before - 2] != max) {
			found = true;
			pos = monsrers_after + monsrers_before - start;
			toeat_r = 0;
			toeat_l = monsrers_before - 1 - start;
		}
		else {
			pos = monsrers_after + 2;
			toeat_r = monsrers_before - 2 - start;
			toeat_l = 1;
			for (int i = start + 1; i < monsrers_before - 1;i++) {
				if (before[i] == max && (before[i + 1] != max || before[i - 1] != max)) {
					found = true;
					
					if (before[i + 1] != max) {
						toeat_r--;
						eat_i[m] = pos;
						eat_direction[m] = 'R';
					}
					else {
						toeat_l--;
						eat_i[m] = pos;
						eat_direction[m] = 'L';
						pos--;
					}
					m++;
					break;
				}
				pos++;
				toeat_l++;
				toeat_r--;
			}
		}
		if (!found) {
			cout << "NO\n";
			return 0;
		}
		while (toeat_l > 0) {
			toeat_l--;
			eat_i[m] = pos;
			eat_direction[m] = 'L';
			pos--;
			m++;
		}
		while (toeat_r > 0) {
			toeat_r--;
			eat_i[m] = pos;
			eat_direction[m] = 'R';
			m++;
		}
		monsrers_after++;
	}
	if (m < n - k) {
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	for (int i = 0; i < n - k; i++) {
		cout << eat_i[i] << " " << eat_direction[i] << "\n";
	}
	return 0;
}