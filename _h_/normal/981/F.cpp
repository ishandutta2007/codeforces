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

	int n, l;
	cin >> n >> l;

	vector<ll> a(n), b(n);
	trav(x, a) cin >> x;
	trav(x, b) cin >> x;
	sort(all(a));
	sort(all(b));

	rep(i,0,n){
		a.push_back(a[i]+l);
		b.push_back(b[i]+l);
	}

	int lo = -1, hi = l/2;
	while(lo+1 < hi){
		int mi = (lo+hi)/2;

		vi miss(2*n), see(2*n);
		
		for(int i=0, cur=0; i < 2*n; ++i){
			while(cur<2*n && a[cur] < b[i]-mi) ++cur;
			miss[i] = cur;
		}
		for(int i=0, cur=0; i < 2*n; ++i){
			while(cur<2*n && a[cur] <= b[i]+mi) ++cur;
			see[i] = cur;
		}
		rep(i,0,2*n) miss[i] -= i;
		rep(i,0,2*n) see[i]  -= i;

		deque<int> ko;

		int s = 0;
		while(b[s]-mi < 0) ++s;
		int t = 2*n;
		while(b[t-1]+mi >= 2*l) --t;

		int pr = s;
		rep(j,s,t){
			if(j-pr==n){
				if(!ko.empty() && ko[0]==miss[pr])
					ko.pop_front();
				++pr;
			}

			while(!ko.empty() && ko.back() < miss[j])
				ko.pop_back();
			ko.push_back(miss[j]);

			if(ko[0] >= see[j]) goto fail;
		}
		
		hi = mi;
		continue;
		fail:
		lo = mi;
	}

	cout << hi << endl;
}