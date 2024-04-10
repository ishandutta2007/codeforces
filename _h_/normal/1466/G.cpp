#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < b; ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define trav(x, v) for(auto &x : v)
#define all(v) (v).begin(),(v).end()
#define sz(v) (int)(v).size()
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

const ll md = 1e9+7;
const ll prime = 826301243804089, base = 5131; 

int occs(string &t, string &s){
	// how many times is t in s
	if(sz(t) > sz(s)) return 0;
	ll tval = 0, sval = 0;
	trav(c, t) tval = (tval * base + c-'a') % prime;
	rep(i,0,sz(t)) sval = (sval * base + s[i]-'a') % prime;
	int ans = tval == sval;
	ll bp = 1;
	rep(_,0,sz(t)) bp = bp * base % prime;
	rep(i,sz(t),sz(s)){
		sval = (sval * base + s[i]-'a' - (s[i-sz(t)]-'a') * bp) % prime;
		if((sval - tval) % prime == 0) ++ans;
	}
	return ans;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int n, q;
	cin >> n >> q;

	string s0, t;
	cin >> s0 >> t;
	string sb = s0;
	vi lob(1e6, n);
	rep(i,0,sz(s0)+1) lob[i] = 0;
	rep(i,0,sz(t)) if(sz(sb) < 1e6){
		int pr = sz(sb);
		sb = sb + t[i] + sb;
		rep(j,pr+1,min(sz(sb)+1, int(1e6))) lob[j] = i+1;
	}

	vector<vl> pret(n+1, vl(27, 0));
	pret[0][26] = 1;
	rep(i,0,n){
		rep(tt,0,27)
			pret[i+1][tt] = pret[i][tt] * 2 % md;
		++pret[i+1][t[i]-'a'];
	}

	rep(_,0,q){
		int k;
		cin >> k;
		string w;
		cin >> w;

		ll ans = occs(w, s0) * pret[k][26] % md;

		vector<bool> good(sz(w), true);
		ll sval = 0, tval = 0, bp = 1;
		rep(i,0,sz(w)-1){
			tval = (tval * base + w[i] - 'a') % prime;
			sval = (sval + bp * (sb[sz(sb)-1-i]-'a')) % prime;
			bp = bp * base % prime;
			good[i+1] = (good[i+1] && (sval - tval) % prime == 0);
		}
		bp = 1, sval = tval = 0;
		rrep(i,0,sz(w)-1){
			tval = (tval + bp * (w[i+1]-'a')) % prime;
			sval = (sval * base + sb[sz(w)-2-i] - 'a') % prime;
			bp = bp * base % prime;
			good[i] = (good[i] && (sval - tval) % prime == 0);
		}

		rep(i,0,sz(w)) if(good[i]){
			int fr = lob[max(i, sz(w)-i-1)];
			if(fr >= k) continue;
			ans = (ans + pret[k][w[i]-'a'] - pret[k-fr][26] * pret[fr][w[i]-'a']) % md;
		}

		if(ans < 0) ans += md;
		cout << ans << endl;
	}
}