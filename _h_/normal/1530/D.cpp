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
	trav(a, as) cin >> a, --a;

	vector<vi> ls(n);
	rep(i,0,n) ls[as[i]].push_back(i);

	vi ins, outs;

	rep(i,0,n){
		if(sz(ls[i]) == 0){
				ins.push_back(i);
		} else if(sz(ls[i]) >= 2){
			if(sz(ls[ls[i][1]]) == 0){
				swap(ls[i][1], ls[i][0]);	
			}
			rep(k,1,sz(ls[i])) outs.push_back(ls[i][k]);
		}
	}

	sort(all(ins));
	sort(all(outs));
	reverse(all(outs));

	rep(k,0,sz(ins)) if(ins[k] == outs[k]){
		if(k > 0) swap(ins[k], ins[k-1]);
		else swap(ins[k], ins[k+1]);
	}

	rep(k,0,sz(ins)) as[outs[k]] = ins[k];
	cout << n - sz(ins) << endl;
	trav(a, as) cout << a+1 << " ";
	cout << endl;
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