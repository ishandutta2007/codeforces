
// Problem : F. Integer Game
// Contest : Codeforces - Codeforces Global Round 9
// URL : https://codeforces.com/contest/1375/problem/F
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

long long a[3];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> a[0] >> a[1] >> a[2];
	cout << "First" << endl;
	while(1){
		int mxidx = max_element(a, a+3) - a + 1;
		long long v = 3 * a[mxidx-1] - a[0] - a[1] - a[2];
		cout << v << endl;
		int i;
		cin >> i;
		a[i-1] += v;
		if(i != mxidx){
			v = 2 * a[mxidx-1] - a[0] - a[1] - a[2] + a[i-1];
			cout << v << endl;
			break;
		}
	}
}