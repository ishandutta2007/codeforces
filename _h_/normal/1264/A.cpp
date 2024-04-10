// written by aitch
// on 2019 12/05 at 14:35:01
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define all(v) (v).begin(),(v).end()
#define trav(x,v) for(auto &x : v)
#define sz(v) int(v.size())
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pii;

void solve(){
	int n;
	cin >> n;

	vi p(n);
	trav(x,p) cin >> x;

	vi ls;
	for(int i = 0; i < n;){
		int j = i+1;
		while(j < n && p[j] == p[i]) ++j;
		ls.push_back(j-i);
		i = j;
	}
	int g = ls[0], s = 0, b = 0;
	for(int cur = 1; cur < sz(ls); ++cur){
		if(s > g){
			if(2*(g+s+b+ls[cur]) > n){
				if(b <= g || 2*(g+s+b)>n) cout << "0 0 0" << endl;
				else cout << g << " " << s << " " << b << endl;
				return;
			} else {
				b += ls[cur];
			}
		} else {
			s += ls[cur];
		}
	}
	cout << "0 0 0" << endl;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	rep(_,0,n) solve();
}