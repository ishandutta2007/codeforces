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

ll good[30] = {}, bad[30] = {};

void rec(vi &a, int t){
	if(t == -1 || a.empty()) return;
	vector<vi> ls(2);
	rep(i,0,sz(a)){
		if(a[i] & (1<<t)){
			good[t] += sz(ls[0]);	
			ls[1].push_back(a[i]);
		} else {
			bad[t] += sz(ls[1]);
			ls[0].push_back(a[i]);
		}
	}
	rep(i,0,2) rec(ls[i], t-1);
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int n;
	cin >> n;
	vi a(n);
	trav(x, a) cin >> x;
	rec(a, 29);

	ll b = 0;
	int x = 0;
	rep(i,0,30){
		if(good[i] >= bad[i]){
			b += bad[i];
		} else {
			b += good[i];
			x += 1 << i;
		}
	}
	cout << b << " " << x << endl;
}