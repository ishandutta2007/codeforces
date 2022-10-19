#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

string s;

int main(){
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while(T--){
		cin >> s;
		int ans0 = 10, ans1 = 10;
		int cnt[2] = {0, 0};
		rep(i, 10){
			if(s[i] == '1')
				cnt[i & 1]++;
			else if(s[i] == '?'){
				if(i & 1)
					cnt[i & 1]++;
			}
			if(cnt[1] > cnt[0] + (9 - i) / 2){
				ans0 = i + 1;
				break;
			}
		}
		cnt[0] = cnt[1] = 0;
		rep(i, 10){
			if(s[i] == '1')
				cnt[i & 1]++;
			else if(s[i] == '?'){
				if(!(i & 1))
					cnt[i & 1]++;
			}
			if(cnt[0] > cnt[1] + (10 - i) / 2){
				ans1 = i + 1;
				break;
			}
		}
		cout << min(ans0, ans1) << endl;
	}
	return 0;
}