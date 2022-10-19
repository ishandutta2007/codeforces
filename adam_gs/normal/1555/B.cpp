#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") 
#pragma GCC option("arch=native","tune=native","no-zero-upper") 
#pragma GCC target("avx2","popcnt","rdrnd","bmi2")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const ll INF=1e18+7;
void solve() {
	ll W, H;
	cin >> W >> H;
	ll x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	ll w, h;
	cin >> w >> h;
	ll sumx=w+x2-x1, sumy=h+y2-y1;
	if(sumx>W && sumy>H) {
		cout << -1 << '\n';
		return;
	}
	ll ans=INF;
	ll akt=0;
	if(sumx<=W) {
		if(x1<w) akt+=(w-x1);
		ans=min(ans, akt);
	}
	akt=0;
	if(sumy<=H) {
		if(H-h<y2) akt=(y2-(H-h));
		ans=min(ans, akt);
	}
	akt=0;
	if(sumy<=H) {
		if(y1<h) akt=(h-y1);
		ans=min(ans, akt);
	}
	akt=0;
	if(sumx<=W) {
		if(W-w<x2) akt+=(x2-(W-w));
		ans=min(ans, akt);
	}
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	cin >> _;
	while(_--) solve();
}