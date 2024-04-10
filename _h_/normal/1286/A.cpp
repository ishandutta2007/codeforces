#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define all(v) (v).begin(),(v).end()
#define trav(x,v) for(auto &x : v)
#define sz(v) int(v.size())
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int n;
	cin >> n;

	vi p(n);
	trav(x, p) cin >> x;

	if(count(all(p),0) == n){
		cout << (n==1 ? 0 : 1) << endl;
		return 0;
	}

	vi cnt(2);
	rep(i,1,n+1) cnt[i%2]++;
	trav(x,p) if(x) --cnt[x%2];

	int ans = 0;
	rep(i,1,n) if(p[i] && p[i-1] && (p[i]+p[i-1])%2) ++ans;

	vector<vi> ls(2);
	vector<vi> mblen(2);

	rep(i,0,n) if(!p[i] && (!i || p[i-1])){
		int j = i+1;
		while(j < n && !p[j]) ++j;
		if(!i){
			mblen[p[j]%2].push_back(j-i);		
		} else if(j == n){
			mblen[p[i-1]%2].push_back(j-i);		
		} else if(p[i-1]%2 == p[j]%2){
			ls[p[i-1]%2].push_back(j-i);	
		} else {
			++ans;
		}
	}
	trav(v, ls) sort(all(v));
	trav(v, mblen) sort(all(v));
	
	vi rek(2, 1000);
	rep(t,0,2){
		rep(i,0,sz(ls[t])+1) rep(j,0,sz(mblen[t])+1){
			int num = 0;
			rep(ii,0,i) num += ls[t][ii];
			rep(jj,0,j) num += mblen[t][jj];
			if(num <= cnt[t])
				rek[t] = min(rek[t], 2*(sz(ls[t])-i)
						+ sz(mblen[t])-j);
		}
	}
	cout << ans + rek[0] + rek[1] << endl;
}