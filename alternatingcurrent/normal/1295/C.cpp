#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int T;
string s, t;
int ns, nt;
int nxt[30][100100];

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> s >> t;
		ns = s.size(), nt = t.size();
		rep(i, 26) nxt[i][ns] = ns;
		for(int i = ns-1; i >= 0; i--){
			rep(c, 26) nxt[c][i] = nxt[c][i+1];
			nxt[s[i] - 'a'][i] = i;
		}
		int now = 0, ans = 0;
		while(now < nt){
			ans++;
			int pre = now;
			int pos_in_s = nxt[t[now] - 'a'][0]+1;
			while(now < nt && pos_in_s <= ns){
				now++;
				if(now < nt) pos_in_s = nxt[t[now] - 'a'][pos_in_s]+1;
			}
			if(now == pre){
				ans = -1;
				break;
			}
		}
		cout << ans << endl;
	}
	return 0;
}