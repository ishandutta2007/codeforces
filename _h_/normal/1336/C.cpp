#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> (b);)
#define trav(x,v) for(auto &x : (v))
#define all(v) (v).begin(),(v).end()
#define sz(v) (int)(v).size()
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

const ll md = 998244353;

ll mem[3001][3001];

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);

	rep(i,0,3001) rep(j,0,3001) mem[i][j] = -1;

	string s, t;
	cin >> s >> t;

	function<ll(int,int)> calc = [&](int l, int r){
		if( mem[l][r] == -1){
			ll cur = 0;
			if(l == 0 && r >= sz(t)){
				cur++;
			}
			if(r-l < sz(s)){
				char c = s[r-l];
				if(l && (l-1 >= sz(t) || t[l-1] == c)) cur += calc(l-1,r);
				if(r < sz(s) && (r >= sz(t) || t[r] == c)) cur += calc(l, r+1);
			}
			mem[l][r] = cur % md;
		}
		return mem[l][r];
	};
	ll ans = 0;
	rep(i,0,sz(s)+1) ans += calc(i,i);
	ans %= md;
	cout << ans << endl;
}