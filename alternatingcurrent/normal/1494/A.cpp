#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int Q;
string s;

int main(){
	ios::sync_with_stdio(false);
	cin >> Q;
	while(Q--){
		cin >> s;
		int now = 0;
		bool ans = 0;
		rep(mask, 8){
			now = 0;
			bool ok = 1;
			rep(i, (int)s.size()){
				if(mask & (1 << (s[i] - 'A'))) now++;
				else now--;
				if(now < 0){
					ok = 0;
					break;
				}
			}
			if(now) ok = 0;
			if(ok){
				ans = 1;
				break;
			}
		}
		if(ans) cout <<"YES" <<endl;
		else cout << "NO" << endl;
	}
	return 0;
}