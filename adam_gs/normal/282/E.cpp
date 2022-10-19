#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define all(a) a.begin(), a.end()
const int LIM=1e5+7;
ll T[LIM], w=1;
vector<pair<int,int>>trie; // st - 0, nd - 1
void upd(ll x) { // dodaje do trie element x
	ll akt=0;
	for(ll i=49; i>=0; --i) {
		if(x&(w<<i)) {
			if(trie[akt].nd==-1) {
				trie[akt].nd=trie.size();
				trie.pb({-1, -1});
			}
			akt=trie[akt].nd;
		} else {
			if(trie[akt].st==-1) {
				trie[akt].st=trie.size();
				trie.pb({-1, -1});
			}
			akt=trie[akt].st;
		}
	}
}
ll cnt(ll x) { // znajduje y takie ze x^y jest maksymalne
	ll akt=0, ans=0;
	for(ll i=49; i>=0; --i) {
		if(x&(w<<i)) { // chce przejsc przez st
			if(trie[akt].st!=-1) {
				akt=trie[akt].st;
			} else {
				ans+=(1<<i);
				akt=trie[akt].nd;
			}
		} else { // chce przejsc przez nd
			if(trie[akt].nd!=-1) {
				ans+=(w<<i);
				akt=trie[akt].nd;
			} else {
				akt=trie[akt].st;
			}
		}
	}
	return ans;
}
void solve() {
	trie.pb({-1, -1});
	int n;
	cin >> n;
	ll x=0, ans=0, suf=0;
	rep(i, n) {
		cin >> T[i];
		x^=T[i];
	}
	ans=x;
	upd(0);
	for(int i=n-1; i>=0; --i) {
		x^=T[i];
		suf^=T[i];
		upd(suf);
		ans=max(ans, x^cnt(x));
	}
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	//cin >> _;
	while(_--) solve();
}