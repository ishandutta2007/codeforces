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
typedef vector<ll> vl;

const ll md = 998244353;
int m = 26+26+10;

int ren(char c){
	if('a' <= c && c <= 'z')
		return  0+c-'a';
	if('A' <= c && c <= 'Z')
		return 26+c-'A';
	else
		return 52+c-'0';
}

ll cnt(vector<vl> &ws){
	vector<vector<vl>> pyr(m, vector<vl>(m, vl(m)));
	rep(i,0,m) rep(j,i,m) rep(k,j,m){
		rep(t,0,m)
		pyr[i][j][k] = (pyr[i][j][k] + 
		ws[i][t] * ws[j][t] * ws[k][t])%md;
	}
	ll ans = 0;
	rep(a,0,m) rep(b,a,m) rep(c,b,m) rep(d,c,m){
		ll cur = pyr[a][b][c]
			*pyr[a][b][d]%md
			*pyr[a][c][d]%md
			*pyr[b][c][d]%md;
		int dis = 4 - (a==b)-(b==c)-(c==d);
		int syms = -1;
		if(dis == 4) syms = 1;
		else if(dis == 3) syms = 2;
		else if(dis == 2){
			syms = b==c ? 6 : 4;
		} else syms = 24;
		cur *= 24 / syms;
		ans = (ans + cur) % md;
	}
	return ans;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<set<string>> words(11);

	rep(_,0,n){
		string s;
		cin >> s;
		int l = sz(s);
		words[l].insert(s);
		reverse(all(s));
		words[l].insert(s);
	}
	ll ans = 0;
	rep(l,3,11) if(true){
		vector<vl> ws(m, vl(m));
		trav(s, words[l])
			ws[ren(s[0])][ren(s[l-1])]++;
		ll res = cnt(ws);
		ans += res;
	}
	ans %= md;
	cout << ans << endl;
}