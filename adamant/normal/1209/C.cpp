#include<bits/stdc++.h>
 
using namespace std;

#define int int64_t

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	for(auto &it: s) {
		it -= '0';
	}
	for(int z = 0; z <= 9; z++) {
		//cout << "!! " << z << endl;
		deque<int> A, B;
		for(int i = 0; i < n; i++) {
			if(s[i] > z) {
				B.push_back(i);
			} else if(s[i] < z) {
				A.push_back(i);
			}
		}
		deque<int> C;
		for(int i = 0; i < n; i++) {
			if(s[i] == z) {
				if(A.empty() || i > A.back()) {
					A.push_back(i);
				} else {
					C.push_back(i);
				}
			}
		}
		while(C.size() && (B.empty() || C.back() < B[0])) {
			B.push_front(C.back());
			C.pop_back();
		}
		bool ok = (int)A.size() + (int)B.size() == n;
		for(size_t i = 1; i < A.size(); i++) {
			//cout << "A " << int(s[A[i]]) << ' ' << int(s[A[i-1]]) << endl;
			ok &= s[A[i]] >= s[A[i - 1]];
		}
		//cout << ok << endl;
		for(size_t i = 1; i < B.size(); i++) {
			//cout << int(s[B[i]]) << ' ' << int(s[B[i-1]]) << endl;
			ok &= s[B[i]] >= s[B[i - 1]];
		}
		if(ok) {
			int ans[n];
			for(auto it: A) {
				ans[it] = 1;
			}
			for(auto it: B) {
				ans[it] = 2;
			}
			for(auto it: ans) {
				cout << it;
			}
			cout << "\n";
			return;
		}
	}
	cout << "-" << "\n";
}

signed main() {
	//freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0); 
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
		solve();
	}
}