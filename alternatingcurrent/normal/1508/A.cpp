#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int T;
int n;
string s[3];
int cnt0 = 0, cnt1 = 0, cnt2 = 0;
int pos0 = 0, pos1 = 0, pos2 = 0;
string ans[3];

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n;
		ans[0] = "", ans[1] = "", ans[2] = "";
		rep(i, 3) cin >> s[i];
		pos0 = pos1 = pos2 = 0, cnt0 = cnt1 = cnt2 = 0;
		while(pos0 < n + n && pos1 < n + n && pos2 < n + n){
			if(s[0][pos0] == s[1][pos1] && s[1][pos1] == s[2][pos2]) cnt0++, cnt1++, cnt2++, ans[0] += (s[0][pos0]), ans[1] += (s[1][pos1]), ans[2] += (s[2][pos2]), pos0++, pos1++, pos2++;
			else if(s[0][pos0] == s[1][pos1]) cnt0++, ans[0] += (s[0][pos0]), ans[1] += (s[0][pos0]), ans[2] += (s[0][pos0]), pos0++, pos1++;
			else if(s[1][pos1] == s[2][pos2]) cnt1++, ans[1] += (s[1][pos1]), ans[2] += (s[1][pos1]), ans[0] += (s[1][pos1]), pos1++, pos2++;
			else if(s[2][pos2] == s[0][pos0]) cnt2++, ans[2] += (s[2][pos2]), ans[0] += (s[2][pos2]), ans[1] += (s[2][pos2]), pos2++, pos0++;
		}
		if(cnt0 >= n){
			cout << ans[0];
			while(pos0 < n + n) cout << s[0][pos0], pos0++;
			while(pos1 < n + n) cout << s[1][pos1], pos1++;
			cout << endl;
		} else if(cnt1 >= n){
			cout << ans[1];
			while(pos1 < n + n) cout << s[1][pos1], pos1++;
			while(pos2 < n + n) cout << s[2][pos2], pos2++;
			cout << endl;
		} else {
			cout << ans[2];
			while(pos2 < n + n) cout << s[2][pos2], pos2++;
			while(pos0 < n + n) cout << s[0][pos0], pos0++;
			cout << endl;
		}
	}
	return 0;
}