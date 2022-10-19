#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while(T--){
		int ans = 0x3f3f3f3f;
		int n;
		string s, t;
		cin >> n >> s >> t;
		int cnt0 = 0, cnt1 = 0;
		rep(i, n){
			cnt0 += s[i] < t[i];
			cnt1 += s[i] > t[i];
		}
		if(cnt1 == cnt0)
			ans = cnt0 + cnt1;
		rep(i, n)
			if(t[i] == '0')
				t[i] = '1';
			else
				t[i] = '0';
		cnt0 = 0, cnt1 = 0;
		rep(i, n){
			cnt0 += s[i] < t[i];
			cnt1 += s[i] > t[i];
		}
		if(cnt1 == cnt0 + 1)
			ans = min(ans, cnt0 + cnt1);
		cout << (ans < 0x3f3f3f3f ? ans : -1) << endl;
	}
	return 0;
}