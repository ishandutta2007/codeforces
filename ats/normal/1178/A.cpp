#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;
#define int long long
int MOD = 1000000007;
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<int> A(N);
	vector<int> res;
	int tot = 0;
	int sum = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		tot += A[i];
		if(i == 0){
			res.push_back(i + 1);
			sum += A[0];
		}else{
			
			if (A[0] >= A[i] * 2) {
				res.push_back(i + 1);
				sum += A[i];
			}
		}
	}
	
	if (tot < 2 * sum) {
		cout << res.size() << endl;
		for (int i = 0; i < res.size(); i++) {
			if (i > 0)cout << " ";
			cout << res[i];
		}
		cout << endl;
	}
	else {
		cout << 0 << endl;
	}
}