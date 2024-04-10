#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define all(v) (v).begin(),(v).end()
#define trav(x,v) for(auto &x : v)
#define sz(v) int(v.size())
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	string s;
	cin >> s;
	int q;
	cin >> q;
	int n = sz(s);
	vector<vi> cnt(26, vi(n+1));
	rep(i,0,n){
		rep(t,0,26) cnt[t][i+1] = cnt[t][i];
		++cnt[s[i]-'a'][i+1];
	}
	auto good = [&](int l, int r){
		if(r-l == 1) return true;
		int diff = 0;
		rep(t,0,26) diff += cnt[t][r]>cnt[t][l];
		if(diff > 2) return true;
		if(diff == 2 && s[l] != s[r-1]) return true;
		return false;
	};
	rep(_,0,q){
		int l, r;
		cin >> l >> r;
		--l;
		cout << (good(l,r) ? "Yes" : "No") << endl;
	}
}