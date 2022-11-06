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

struct str {
	str *l = 0, *r = 0;
	int fr, to, mi;
	char c = 'a';
	bool bo = 0;
	str(int fr, int to) : fr(fr), to(to) {
		mi = (fr + to)/2;
		if(to-fr > 1){
			l = new str(fr, mi);
			r = new str(mi, to);
		}
	}

	void set(int k, string &t){
		if(bo || k+sz(t) <= fr ||
			k >= to) return;
		if(fr+1 == to){
			bo = 1;
			c = t[fr - k];
		} else {
			l->set(k, t);
			r->set(k, t);
			bo = l->bo && r->bo;
		}
	}

	void print(int len){
		if(fr >= len) return;
		if(fr+1 == to) cout << c;
		else l->print(len), r->print(len);
	}

};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	str s(0, 2e6);
	int n, len = 0;
	cin >> n;
	rep(_,0,n){
		string t;
		cin >> t;
		int k;
		cin >> k;
		rep(_,0,k){
			int x;
			cin >> x;
			--x;
			len = max(len, x+sz(t));
			s.set(x, t);
		}
	}
	s.print(len);
}