
// Problem : B. A Determined Cleanup
// Contest : Codeforces - Codeforces Round #462 (Div. 1)
// URL : https://codeforces.com/contest/933/problem/B
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

long long x, b;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> x >> b;
	b *= -1;
	vector<long long> vec;
	while(x){
		//cout << "here" << endl;
		//cout << x << " " << b << endl;
		long long r = x%b;
		//cout << r << endl;
		x /= b;
		//cout << r << endl;
		//cout << "here" << endl;
		if(r < 0){
			r -= b;
			x++;
		}
		//cout << "here" << endl;
		vec.push_back(r);
		//cout << x << endl;
	}
	cout << vec.size() << "\n";
	for(int n : vec){
		cout << n << " ";
	}
}