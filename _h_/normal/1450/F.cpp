#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < b; ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define trav(x, v) for(auto &x : v)
#define all(v) (v).begin(),(v).end()
#define sz(v) (int)(v).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

void solve(){
	int n;
	cin >> n;
	vi as(n);
	trav(x, as) cin >> x, --x;
	vi cnt(n);
	for(int l = 0, r = 0; l < n;){
		while(r+1 < n && as[r+1] != as[r]) ++r;
		++cnt[as[l]];
		++cnt[as[r]];
		l = r+1;
		r = l;
	}
	int tot = 0;
	trav(x, cnt) tot += x;
	int rek = 0;
	rep(i,0,n) if(cnt[i] > cnt[rek]) rek = i;
	int available = 0;
	for(int l = 0, r = 0; l < n;){
		while(r+1 < n && as[r+1] != as[r]) ++r;
		rep(i,l,r) if(as[i] != rek && as[i+1] != rek){
			++available;
		}
		l = r+1;
		r = l;
	}
	int ans = tot/2 - 1;
	while(cnt[rek] + cnt[rek] - 2 > tot){
		if(available == 0){
			cout << -1 << endl;
			return;
		}
		--available;
		++ans;
		tot += 2;
	}
	cout << ans << endl;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int n;
	cin >> n;

	rep(_,0,n){
		solve();
	}
}