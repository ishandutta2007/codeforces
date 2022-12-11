
// Problem : D1. Two Hundred Twenty One (easy version)
// Contest : Codeforces - Codeforces Round #741 (Div. 2)
// URL : https://codeforces.com/contest/1562/problem/D1
// Memory Limit : 512 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T;
int N, Q;
string s;
int pre[300005];

int bs(int l, int r){
	int tar = pre[l-1] + pre[r];
	bool lessthan = pre[l-1] < pre[r];
	//cout << tar << "\n";
	//cout << pre[l-1] << " " << pre[r] << "\n";
	while(l <= r){
		int mid = (l + r) / 2;
		//cout << "mid: " << mid << " " << pre[mid] + pre[mid-1] << "\n";
		if(pre[mid] + pre[mid-1] == tar){
			return mid;		
		}
		else if(pre[mid] + pre[mid-1] > tar && lessthan){
			r = mid - 1;
			//l = mid + 1;
		}
		else if(pre[mid] + pre[mid-1] < tar && !lessthan){
			r = mid - 1;
			//l = mid + 1;
		}
		else{
			l = mid + 1;
			//r = mid - 1;
		}
	}
	assert(0);
	return 0;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		cin >> N >> Q;
		cin >> s;
		//cout<< "prefix\n";
		for(int i = 1; i <= N; i++){
			if(i%2 == 0){
				pre[i] = pre[i-1] + (-1) * (s[i-1] == '+' ? 1 : -1);
			}
			else{
				pre[i] = pre[i-1] + (s[i-1] == '+' ? 1 : -1);
			}
			//cout << i << " " << (pre[i] + pre[i-1]) << "\n";
		}
		for(int q = 1; q <= Q; q++){
			int l, r;
			cin >> l >> r;
			if(pre[r] - pre[l-1] == 0){
				cout << 0 << "\n";
			}
			else if((r - l + 1) % 2){
				cout << 1 << "\n";
				cout << bs(l, r) << "\n";
			}
			else{
				cout << 2 << "\n";
				cout << l << " " << bs(l+1, r) << "\n";
			}
		}
		
	}
}