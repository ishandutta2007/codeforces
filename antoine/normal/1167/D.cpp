#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;



	int sum0 = 0, sum1 = 0;
	while(n--) {
		char ch;
		cin >> ch;
		if(ch == '(') {
			if(sum0 <= sum1) {
				cout << 0;
				sum0++;
			} else{
				cout << 1;
				sum1++;
			}
		} else {
			if(sum0>= sum1) {
				cout << 0;
				sum0--;
			}else{
				cout<<1;sum1--;
			}
		}
	}
	return 0;
}