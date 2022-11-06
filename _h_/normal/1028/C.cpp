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

const int inf = 1e9+1;

const pii upp(inf, inf), ner(-inf, -inf);

pii mn(pii a, pii b){
	return pii(min(a.first, b.first), min(a.second, b.second));
}

pii mx(pii a, pii b){
	return pii(max(a.first, b.first), max(a.second, b.second));
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;

	vector<pii> lo(n), hi(n);
	rep(i,0,n)
		cin >> lo[i].first >> lo[i].second
		>> hi[i].first >> hi[i].second;

	vector<pii> lpre(n+1), lsuf(n+1),
		    hpre(n+1), hsuf(n+1);

	lpre[0] = ner;
	rep(i,0,n) lpre[i+1] = mx(lpre[i], lo[i]);	
	lsuf[n] = ner;
	rrep(i,0,n) lsuf[i] = mx(lsuf[i+1], lo[i]);

	hpre[0] = upp;
	rep(i,0,n) hpre[i+1] = mn(hpre[i], hi[i]);	
	hsuf[n] = upp;
	rrep(i,0,n) hsuf[i] = mn(hsuf[i+1], hi[i]);

	rep(i,0,n){
		pii a = mx(lpre[i], lsuf[i+1]),
		    b = mn(hpre[i], hsuf[i+1]);
		if(a.first <= b.first && a.second <= b.second){
			cout << a.first << ' ' << a.second << endl;
			return 0;
		}
	}
}