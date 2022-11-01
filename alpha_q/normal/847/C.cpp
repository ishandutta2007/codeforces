#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 

int main(int argc, char const *argv[]) {
	ll n, k; string str = "";  
	cin >> n >> k;
	if(n * (n - 1) / 2 < k) {
		return 0 * puts("Impossible");
	} 
	ll cnt = 0, bal = 0;
	for(int i = 0; i < 2 * n; i++) {
		if(bal + cnt <= k) {
			str += "("; 
			bal += cnt++;
		} else {
			str += ")"; cnt--;
		}
	}
	if(bal != k) str = "Impossible";
	cout << str << endl;
}