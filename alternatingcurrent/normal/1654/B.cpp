#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int T;
string s;
int cnt[33];

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> s;
		memset(cnt, 0, sizeof(cnt));
		rep(i, (int)s.size()){
			cnt[s[i] - 'a']++;
		}
		rep(i, (int)s.size()){
			cnt[s[i] - 'a']--;
			if(cnt[s[i] - 'a'] == 0){
				for(int j = i; j < (int)s.size(); j++)
					cout << s[j];
				cout << endl;
				break;
			}
		}
	}
	return 0;
}