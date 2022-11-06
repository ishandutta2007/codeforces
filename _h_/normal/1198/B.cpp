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

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vi as(n), ts(n,-1);
	trav(x, as) cin >> x;

	vector<pii> mq = { pii(1e9+1, -2) };

	int q;
	cin >> q;
	rep(t,0,q){
		int type;
		cin >> type;
		if(type == 1){
			int p, x;
			cin >> p >> x;
			--p;
			as[p] = x;
			ts[p] = t;
		} else {
			int x;
			cin >> x;
			while(mq.back().first <= x) mq.pop_back();
			mq.emplace_back(x, t);
		}
	}
	mq.emplace_back(0, q);
	rep(i,0,n){
		int lo = 0, hi = sz(mq)-1;
		while(lo+1 < hi){
			int mi = (lo+hi)/2;
			if(mq[mi].second > ts[i]) hi = mi;
			else lo = mi;
		}
		cout << max(mq[hi].first, as[i]) << ' ';
	}
	cout << endl;
}