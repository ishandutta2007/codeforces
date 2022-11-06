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

int c2(int n){
	return n * (n-1) / 2;
}

string info(vector<string> &ls, int n){
	vector<vi> lencnt(n+1, vi(26));
	trav(s, ls) trav(c, s) ++lencnt[sz(s)][c-'a'];
	vector<string> ps;
	for(int i = 1; 2*i <= n; ++i){
		vi cnt = lencnt[n];
		trav(x, cnt) x *= i+1;
		rep(c,0,26) cnt[c] -= lencnt[n-i][c];
		rep(j,1,i) trav(c, ps[j-1])
			cnt[c-'a'] -= i+1-j;
		ps.push_back("");
		rep(c,0,26) rep(_,0,cnt[c])
			ps.back().push_back(c+'a');	
	}
	if(n%2){
		vi cnt = lencnt[n];
		trav(s, ps) trav(c, s) --cnt[c-'a'];
		ps.push_back("");
		rep(c,0,26) rep(_,0,cnt[c]) ps.back().push_back(c+'a');
	}
	string ans(n, '?');
	int l = 0, r = n;
	trav(s, ps){
		if(sz(s) == 1){
			ans[l] = s[0];
		} else {
			ans[l++] = s[0];
			ans[--r] = s[1];
		}
	}
	return ans;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int n;
	cin >> n;

	if(n == 1){
		cout << "? 1 1" << endl;
		string s;
		cin >> s;
		cout << "! " << s << endl;
		return 0;
	}

	vector<string> l1(c2(n+1)), l2(c2(n));
	cout << "? " << 1 << " " << n << endl;
	trav(s, l1) cin >> s;
	cout << "? " << 1 << " " << n-1 << endl;
	trav(s, l2) cin >> s;
	string a = info(l1, n), b = info(l2, n-1);
	string ans(n, '?');
	vi diff(26);
	trav(c, a) ++diff[c-'a'];
	trav(c, b) --diff[c-'a'];
	function<void(int,char)> setchar = [&](int i, char c){
		ans[i] = c;
		if(n-1-i < i){
			char d = a[i] ^ a[n-1-i] ^ c;
			setchar(n-1-i, d);
		} else if(n-2-i > i){
			char d = b[i] ^ b[n-2-i] ^ c;
			setchar(n-2-i, d);
		}
	};
	rep(c,0,26) if(diff[c]) setchar(n-1, c+'a');
	cout << "! " << ans << endl;
}