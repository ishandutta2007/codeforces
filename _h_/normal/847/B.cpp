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

struct node {
	node *l = 0, *r = 0;
	int mx = 0, fr, to, mi;
	node(int fr, int to, vi &as) : fr(fr), to(to) {
		mi = (fr+to)/2;
		if(mi > fr){
			l = new node(fr, mi, as);
			r = new node(mi, to, as);
			mx = max(l->mx, r->mx);
		} else {
			mx = as[fr];
		}
	}
	void upd(int pos, int val){
		if(mi > fr){
			if(pos < mi) l->upd(pos,val);
			else r->upd(pos,val);
			mx = max(l->mx, r->mx);
		} else {
			mx = val;
		}
	}

	int que(int val, int lo){
		if(to <= lo) return -1;
		if(mx <= val) return -1;
		if(to-fr==1) return fr;
		int res = l->que(val,lo);
		if(res != -1) return res;
		return r->que(val, lo);
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	vi as(n);
	trav(x, as) cin >> x;
	node root(0,n,as);
	vector<bool> used(n);
	rep(i,0,n) if(!used[i]){
		vi cur;
		int j = i;
		while(true){
			cur.push_back(j);
			root.upd(j,0);
			used[j] = 1;
			int nx = root.que(as[j],j+1);
			if(nx == -1) break;
			j = nx;
		}
		trav(x, cur) cout << as[x] << ' '; cout << endl;
	}
	exit(0);
}