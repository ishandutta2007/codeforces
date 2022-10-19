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
		string ans = "";
		rep(c, 26){
			if(cnt[c] == 1){
				ans += (char)(c + 'a');
				for(int i = 0; i < 26; i++)
					if(i != c)
						rep(j, cnt[i])
							ans += (char)(i + 'a');
				break;
			}
		}
		if(ans != ""){
			cout << ans << endl;
			continue;
		}
		rep(i, (int)s.size())
			ans += '.';
		rep(i, 26){
			if(cnt[i] > 0){
				if(cnt[i] <= (int)s.size() / 2 + 1){
					ans[0] = ans[1] = (char)(i + 'a');
					cnt[i] -= 2;
					int pos = 3;
					while(cnt[i]){
						ans[pos] = (char)(i + 'a');
						pos += 2;
						cnt[i]--;
					}
					int nowpos = 2;
					for(int j = i + 1; j < 26; j++){
						rep(k, cnt[j]){
							ans[nowpos] = (char)(j + 'a');
							nowpos++;
							if(nowpos < pos && nowpos % 2 == 1)
								nowpos++;
						}
					}
				} else {
					int nxt = i + 1;
					while(nxt < 26 && !cnt[nxt])
						nxt++;
					if(nxt == 26){
						ans = s;
						break;
					}
					cnt[nxt]--;
					ans[0] = (char)(i + 'a');
					ans[1] = (char)(nxt + 'a');
					if(cnt[i] + cnt[nxt] == (int)s.size() - 1){
						for(int j = 2; j < cnt[nxt] + 2; j++)
							ans[j] = (char)(nxt + 'a');
						for(int j = cnt[nxt] + 2; j < (int)s.size(); j++)
							ans[j] = (char)(i + 'a');
						break;
					}
					cnt[i]--;
					int j = 2;
					for(; cnt[i]; j++){
						ans[j] = (char)(i + 'a');
						cnt[i]--;
					}
					int nxtnxt = nxt + 1;
					while(cnt[nxtnxt] <= 0)
						nxtnxt++;
					ans[j++] = (char)(nxtnxt + 'a');
					cnt[nxtnxt]--;
					for(int k = nxt; k < 26; k++){
						for(int l = 0; l < cnt[k]; l++){
							ans[j++] = (char)(k + 'a');
						}
					}
				}
				break;
			}
		}
		cout << ans << endl;
	}
	return 0;
}