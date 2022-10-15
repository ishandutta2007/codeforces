/*
 *      Author: arsijo;
 */

#include <bits/stdc++.h>
using namespace std;

int main(){
	//freopen("a.in", "r", stdin); freopen("a.out","w",stdout);
	int n, m;
	cin >> m >> n;
	double ans = m;
	for(int i = m-1; i > 0; i--){
		ans -= pow(double(i) / double(m), n);
	}
	cout << ans;
}