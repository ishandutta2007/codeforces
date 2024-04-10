#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1LL * MX * MX;

string s, t;
int last[26];
int nxt[N][26];

void solve(){
	cin >> s >> t;
	for(int i = 0; i < 26; ++i)
		last[i] = s.size();

	for(int i = s.size() - 1; i >= 0; --i){
		for(int j = 0; j < 26; ++j)
			nxt[i + 1][j] = last[j] + 1;
		last[s[i] - 'a'] = i;
	}
	
	for(int i = 0; i < 26; ++i)
		nxt[0][i] = last[i] + 1;
	
	int cur = 0, ans = 0;
	while(cur < (int)t.size()){
		++ans;
		int tmp = 0;
		if(nxt[tmp][t[cur] - 'a'] > (int)s.size()){
			cout << "-1\n";
			return;
		}
		
		while(cur < (int)t.size() && tmp <= (int)s.size()){
			if(nxt[tmp][t[cur] - 'a'] > (int)s.size())
				break;
			
			tmp = nxt[tmp][t[cur] - 'a'];
			++cur;
		}
	}
	
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(false);
	int cases;
	cin >> cases;
	
	while(cases--)
		solve();
	return 0;
}