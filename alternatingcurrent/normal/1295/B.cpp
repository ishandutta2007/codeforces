#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
int qmin(int a, int b){
	return (a < b) ? a : b;
}
int qmax(int a, int b){
	return (a > b) ? a : b;
}
int qabs(int a){
	return (a < 0) ? -a : a;
}

int n, x;
string s;
int cnt[200200];

bool inr(int del, int pos){
	return (del > 0 && pos <= x) || (del < 0 && pos >= x);
}

int main(){
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while(T--){
		cin >> n >> x >> s;
		int balance = 0;
		int mxb = 0, mnb = 2*n;
		memset(cnt, 0, sizeof(cnt));
		rep(i, n){
			cnt[balance+n]++;
			if(s[i] == '0') balance++;
			else balance--;
			mnb = qmin(mnb, balance);
			mxb = qmax(mxb, balance);
		}
		if(balance == 0){
			if(mnb <= x && x <= mxb) cout << "-1" << endl;
			else cout << "0" << endl;
		} else {
			int ans = 0;
			int target = x % balance;
			if(inr(balance, target)) ans += cnt[target + n];
			int to_neg = target-qabs(balance), to_pos = target+qabs(balance);
			while(to_neg >= mnb){
				if(inr(balance, to_neg)) ans += cnt[to_neg + n];
				to_neg -= qabs(balance);
			}
			while(to_pos <= mxb){
				if(inr(balance, to_pos)) ans += cnt[to_pos + n];
				to_pos += qabs(balance);
			}
			cout << ans << endl;
		}
	}
	return 0;
}