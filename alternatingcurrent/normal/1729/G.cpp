#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
const ll Mod = 1e9 + 7;

int T;
string s, t;
int f[505];
ll g[505];

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> s >> t;
		
		vector<int> pos;
		pos.push_back(0xc0c0c0c0);
		rep(i, (int)s.size() - (int)t.size() + 1)
			if(s.substr(i, (int)t.size()) == t)
				pos.push_back(i);
		pos.push_back(0x3f3f3f3f);
		
		static int pre[505], nxt[505];
		for(int i = 0, k = -1; i < (int)pos.size(); ++i){
			while(pos[k+1] + (int)t.size() <= pos[i]) ++k;
//			cout << i << " pre " << k << endl;
			pre[i] = k;
		}
		for(int i = (int)pos.size()-1, k = (int)pos.size(); i >= 0; --i){
			while(pos[k-1] - (int)t.size() >= pos[i]) --k;
//			cout << i << " nxt" << k << endl;
			nxt[i] = k;
		}
		
		memset(f, 0x3f, sizeof(f));
		f[0] = 0, g[0] = 1;
		rep(i, (int)pos.size()) for(int j = i+1; j < (int)pos.size() && pre[j] < nxt[i]; ++j){
			while(pos[i] + (int)t.size() > pos[j]) j++;
//			if(j == i+1) cout << i << ": " << f[i] << " " << g[i] << endl;
			if(f[i] + 1 < f[j])
				f[j] = f[i] + 1, g[j] = g[i];
			else if(f[i] + 1 == f[j])
				g[j] = (g[j] + g[i] >= Mod) ? (g[j] + g[i] - Mod) : (g[j] + g[i]);
		}
		
		cout << f[(int)pos.size() - 1] - 1 << " " << g[(int)pos.size() - 1] << "\n";
	}
	return 0;
}