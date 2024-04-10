#include <iostream>
#include <algorithm>
#include <math.h>
#include <cmath>

using namespace std;

const int mod = 1e9 + 7;

int main(){
	ios_base::sync_with_stdio(false);
	string a;
	cin >> a;
	string s = "0";
	s += a;
	int n = a.size();
	long long ans = 0, k = 0;
	for (int i = n; i >= 0; i--){
		if (s[i] == 'b')
			k ++;
		if (s[i] == 'a'){
			ans += k;
			ans %= mod;
			k *= 2;
			k %= mod;
		}
	}
	cout << ans << endl;
}