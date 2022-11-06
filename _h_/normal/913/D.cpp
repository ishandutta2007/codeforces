#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define rrep(i,a,b) for(int i = b; i --> (a);)
#define all(v) v.begin(),v.end()
#define trav(x,v) for(auto &x : v)
#define sz(v) (int)(v).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	ll n, t;
	cin >> n >> t;
	vector<pair<pii,int>> ta(n);
	trav(pa, ta) cin >> pa.first.second >> pa.first.first;
	rep(i,0,n) ta[i].second = i+1;
	sort(all(ta));
	int lo = 0, hi = n+1;
	while(lo < hi-1){
		int mi = (lo + hi)/2;

		int timeleft = t, solved = 0;
		trav(pa, ta) if(pa.first.second >= mi && pa.first.first <= timeleft){
			++solved;
			timeleft -= pa.first.first;
		}
		if(solved >= mi) lo = mi;
		else hi = mi;
	}
	cout << lo << endl;
	cout << lo << endl;
	int solved = 0;
	for(int i = 0; solved < lo; ++i){
		if(ta[i].first.second >= lo){
			cout << ta[i].second << ' ';
			++solved;
		}
	}
}