#include <iostream>
#include <cmath>
#include <numeric>
#include <vector>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int nbTests;
	cin >> nbTests;
	
	for(int iTest = 0;iTest < nbTests;iTest++) {
		string bits;
		cin >> bits;
		
		int zero = bits.size() + 5;
		
		vector<int> nums(2 * zero + 10, 0);
		
		int s = 0;
		for(char car : bits) {
			if(car == '0') {
				nums[zero + s - 1]++;
				s--;
			}
			else {
				nums[zero + s]++;
				s++;
			}
		}
		
		/*for(int i = -4;i <= 4;i++) {
			cout << nums[zero + i] << endl;
		}*/
		
		int p = zero;
		
		string sol;
		for(int iBit = 0;iBit < (int)bits.size();iBit++) {
			if(nums[p - 1] != 0 && (nums[p - 1] != 1 || nums[p] == 0)) {
				sol.push_back('0');
				nums[p - 1]--;
				p--;
			}
			else {
				sol.push_back('1');
				nums[p]--;
				p++;
			}
		}
		
		cout << sol << endl;
	}
	return 0;
}