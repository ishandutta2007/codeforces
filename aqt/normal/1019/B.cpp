
// Problem : B. The hat
// Contest : Codeforces - Codeforces Round #503 (by SIS, Div. 1)
// URL : https://codeforces.com/contest/1019/problem/B
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

map<int, int> mp;

int query(int n){
	if(mp.count(n)){
		return mp[n];
	}
	cout << "? " << n << endl;
	int x ;
	cin >> x;
	return mp[n] = x;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	if(N%4 == 2){
		cout << "! " << -1 << endl;
		return 0;
	}
	int l = 1, r = N/2+1;
	int vl = query(1) - query(1+N/2), vr = -vl;
	if(!vl){
		cout << "! " << 1 << endl;
		return 0;
	}
	while(l <= r){
		int mid = l+r>>1;
		int v = query(mid) - query(mid+N/2);
		if(v == 0){
			cout << "! " << mid << endl;
			return 0;
		}
		else if((v^vl) >= 0){
			l = mid+1;
			vl = v;
		}
		else {
			r = mid - 1;
			vr = v;
		}
	}
	assert(0);
}