
// Problem : C2. Guessing the Greatest (hard version)
// Contest : Codeforces - Codeforces Round #703 (Div. 2)
// URL : https://codeforces.com/contest/1486/problem/C2
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;

int query(int l, int r){
	if(l == r){
		return -1;
	}
	cout << "? " << l << " " << r << endl;
	int n;
	cin >> n;
	return n;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	int p = query(1, N);
	int ans = p;
	if(query(1, p) == p){
		int l = 1, r = p-1;
		while(l <= r){
			int mid = l+r>>1;
			if(query(mid, p) == p){
				l = mid + 1;
				ans = mid;
			}
			else{
				r = mid - 1;
			}
		}
	}
	else{
		int l = p+1, r = N;	
		while(l <= r){
			int mid = l+r>>1;
			if(query(p, mid) == p){
				r = mid - 1;
				ans = mid;
			}
			else{
				l = mid + 1;
			}
		}
	}
	cout << "! " << ans << endl;
}