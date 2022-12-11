
// Problem : A. Searching Local Minimum
// Contest : Codeforces - Codeforces Round #700 (Div. 1)
// URL : https://codeforces.com/contest/1479/problem/A
// Memory Limit : 512 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
int query(int n){
	if(!n || n == N + 1){
		return INT_MAX / 3;
	}
	cout << "? " << n << endl;
	int k;
	cin >> k;
	return k;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	int l = 1, r = N;
	while(l <= r){
		int mid = l + r >> 1;
		vector<int> v = {query(mid - 1), query(mid), query(mid + 1)};
		if(v[1] < v[0] && v[1] < v[2]){
			cout << "! " << mid << endl;
			return 0;
		}
		else if(v[0] < v[2]){
			r = mid - 1;
		}
		else{
			l = mid + 1;
		}
	}
	assert(0);
}