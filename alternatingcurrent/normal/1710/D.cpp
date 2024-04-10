#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
using namespace std;

int T;
int n;
string oks[2020];
vector<int> ok[2020];

int main(){
	ios::sync_with_stdio(false);
	
	cin >> T;
	while(T--){
		cin >> n;
		rep(i, n)
			cin >> oks[i];
		
		rep(i, n+1)
			ok[i].clear();
		rep(i, n) for(int j = i; j < n; ++j)
			if(oks[i][j-i] == '1')
				ok[j-i+1].push_back(i);
		
		static int par[2020];
		rep(i, n)
			par[i] = i;
		function<int(int)> getpar = [&](int now){ return par[now] == now ? now : par[now] = getpar(par[now]); };
		auto ae = [&](int x, int y){ cout << x+1 << " " << y+1 << "\n"; int px = getpar(x), py = getpar(y); if(px < py) swap(px, py); par[px] = py;};
		for(int len = 2; len <= n; ++len){
			rep(i, (int)ok[len].size()){
				int l = ok[len][i], r = ok[len][i] + len - 1;
				int pl = getpar(l), pr = getpar(r);
				if(pl == pr)
					continue;
				
				vector<int> ps;
				for(int np = getpar(pr-1); np > pl; np = getpar(np-1))
					ps.push_back(np);
				
				ae(l, r);
				if(!ps.empty()){
					for(int j = (int)ps.size()-3; j >= 0; j -= 2)
						ae(ps[j], ps[j+2]);
					ae(ps[(int)ps.size()-1], r);
					
					int st = ((int)ps.size() & 1); // no ```^1```
					for(int j = st+2; j < (int)ps.size(); j += 2)
						ae(ps[j], ps[j-2]);
					ae(ps[st], l);
				}
			}
		}
		
		for(int i = 1; i < n; ++i)
			if(getpar(i) == i)
				ae(i, 0);
	}
	
	return 0;
}