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

void solve(){
	int n, m;
	cin >> n >> m;

	vector<vi> ch(n);
	rep(_,0,m){
		int x, y;
		cin >> x >> y;
		--x, --y;
		if(!count(all(ch[x]), y)){
			ch[x].push_back(y);
		}
	}

	vi danger(n, 0);	

	int cnt = 0;

	rep(i,0,n){
		if(danger[i] <= 1)
			trav(j, ch[i])
				danger[j] = max(danger[j], danger[i]+1);
		else ++cnt;
	}
	cout << cnt << endl;
	rep(i,0,n) if(danger[i] == 2) cout << i+1 << " ";
	cout << endl;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int t;
	cin >> t;
	rep(_,0,t) solve();
}