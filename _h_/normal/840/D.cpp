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

const int mx = 3e5;

int as[mx];
vi ixs[mx+1];

int cnt(int val, int fr, int to){
	return lower_bound(all(ixs[val]), to)
	     - lower_bound(all(ixs[val]), fr);
}

struct node {
	int to, fr, mi;
	vector<vi> ls;
	node *l = 0, *r = 0;
	node(int fr, int to) : to(to), fr(fr) {
		ls.resize(6);
		mi = (fr+to)/2;
		if(to-fr > 1){
			l = new node(fr, mi);
			r = new node(mi, to);
			trav(x, l->ls[5])
				if(cnt(x, fr, to) > (to-fr)/5)
					ls[5].push_back(x);
			trav(x, r->ls[5]) if(!count(all(l->ls[5]),x))
				if(cnt(x, fr, to) > (to-fr)/5)
					ls[5].push_back(x);
			rrep(i,2,5)
				trav(x, ls[i+1])
					if(cnt(x, fr, to) > (to-fr)/i)
						ls[i].push_back(x);
		} else {
			trav(v, ls) v.push_back(as[fr]);
		}
	}
	void add(int le, int ri, int k, set<int> &s){
		if(le >= to || ri <= fr) return;
		if(le <= fr && to <= ri){
			trav(x, ls[k]) s.insert(x);
			return;
		}
		l->add(le,ri,k,s);
		r->add(le,ri,k,s);
	}
};

int main(){
	int n, q;
	scanf("%d%d",&n,&q);
	rep(i,0,n) scanf("%d",as+i);
	rep(i,0,n) ixs[as[i]].push_back(i);
	node root(0, n);
	int l,r,k;
	rep(_,0,q){
		scanf("%d%d%d",&l,&r,&k);
		--l;
		set<int> cnds;
		root.add(l,r,k,cnds);
		trav(x, cnds) if(cnt(x,l,r)>(r-l)/k){
			printf("%d\n",x);
			goto done;
		}
		printf("-1\n");
		done: ;
	}

	exit(0);
}