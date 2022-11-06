#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)
typedef vector<int> vi;
const int mx = 4e4;
vi pr;
bool eras[mx] = {};

bool ispr(int n){
	if(n < mx) return !eras[n];
	for(int &p : pr) if(n % p == 0) return 0;
	return 1;
}


int main(){
	bool eras[mx] = {};
	rep(i,2,mx)
		if(!eras[i]){
			pr.push_back(i);
			for(int j = i+i; j < mx; j += i)
				eras[j] = 1;
		}
	int n;
	cin >> n;
	vi ans;
	if(n <= 5){
		cout << 1 << endl;
		cout << n << endl;
		return 0;
	}
	if(n < mx)
		ans.push_back(3),
		n -= 3;
	else {
		for(int i = n-1000; ; ++i){
			if(ispr(i)){
				ans.push_back(i);
				n -= i;
				break;
			}
		}
	}
	for(int i = 2; ; ++i){
		if(!eras[i] && !eras[n-i]){
			cout << 3 << endl;
			cout << ans[0] << ' ' << i << ' ' << n-i << endl;
			return 0;
		}
	}
}