#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

string s;
int n;
string t;

int main(){
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while(T--){
		cin >> s >> t;
		n = (int)s.size();
		bool ans = 0;
		rep(st, n){
			int cnt = 0;
			for(int r = st; r < n; r++){
				if(s[r] != t[cnt])
					break;
				cnt++;
				if(cnt == (int)t.size()){
					ans = 1;
					break;
				}
				int prcnt = cnt;
				for(int l = r - 1; l >= 0; l--){
					if(s[l] != t[cnt])
						break;
					cnt++;
					if(cnt == (int)t.size()){
						ans = 1;
						break;
					}
				}
				cnt = prcnt;
			}
		}
		if(ans)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}