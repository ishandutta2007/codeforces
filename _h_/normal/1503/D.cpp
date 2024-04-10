#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < b; ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define trav(x, v) for(auto &x : v)
#define all(v) (v).begin(),(v).end()
#define sz(v) (int)(v).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

void fail(){
	cout << -1 << endl;
	exit(0);
}

struct UF {
	vi t;
	UF(int n){
		t.resize(n, -1);
	}
	int find(int a){
		return t[a] < 0 ? a : t[a] = find(t[a]);
	}
	void uni(int a, int b){
		t[a] = b;
	}
};

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int n;
	cin >> n;

	vi as(n), bs(n), lrg(n);
	rep(i,0,n){
		cin >> as[i] >> bs[i];
		--as[i], --bs[i];
		lrg[i] = as[i] < bs[i];
		if(!lrg[i]) swap(as[i], bs[i]);
	}

	int mxa = 1, mnb = 2*n;
	trav(a, as) mxa = max(mxa, a);
	trav(b, bs) mnb = min(mnb, b);
	if(mnb < mxa) fail();

	vector<pair<int, char>> evs(2 * n);

	rep(i,0,n){
		evs[as[i]] = {i, 'a'};
		evs[bs[i]] = {i, 'b'};
	}

	vector<vi> gr(n);
	vector<set<pii>> nextones(n);
	set<pii> curs;
	UF uf(n);

	rep(i,0,2*n){
		if(evs[i].second == 'a'){ // add an arc
			int ix = evs[i].first;
			pii p = {bs[ix], ix};
			vi ls;
			while(!curs.empty()){
				pii q = *curs.begin();
				if(p.first < q.first) break;
				//cerr << 1+p.second << " " << 1+q.second << endl;
				gr[p.second].push_back(q.second);
				gr[q.second].push_back(p.second);
				int c = uf.find(q.second);
				ls.push_back(c);
				nextones[c].insert(q);
				curs.erase(curs.begin());
			}
			nextones[ix].insert(p);
			int bigg = ix;
			trav(c, ls){
				if(sz(nextones[bigg]) < sz(nextones[c]))
					swap(bigg, c);
				uf.uni(c, bigg);
				trav(q, nextones[c]) nextones[bigg].insert(q);
				nextones[c].clear();
			}
			curs.insert(*nextones[bigg].begin());
			nextones[bigg].erase(nextones[bigg].begin());
		} else { // remove an arc
			int ix = evs[i].first;
			pii p = {i, ix};
			int c = uf.find(ix);
			if(nextones[c].count(p)){
				nextones[c].erase(p);
			} else {
				curs.erase(p);
				if(!nextones[c].empty()){
					curs.insert(*nextones[c].begin());
					nextones[c].erase(nextones[c].begin());
				}
			}
		}
	}

	vi sig(n, 0);

	int ans = 0;

	vector<pii> tocheck;

	rep(i,0,n) if(!sig[i]){
		int good = 0, bad = 0;

		stack<int> st;
		sig[i] = 1;
		st.push(i);
		while(!st.empty()){
			int j = st.top();
			st.pop();
			if(lrg[j] == (sig[j]==1)) ++good;
			else ++bad;
			if(sig[j] == 1) tocheck.emplace_back(as[j], bs[j]);
			else tocheck.emplace_back(bs[j], as[j]);
			trav(k, gr[j]){
				if(sig[k] == 0){
					sig[k] = -sig[j];
					st.push(k);
				}
			}
		}
		ans += min(good, bad);
	}
	sort(all(tocheck));
	//cerr << endl;
	//trav(pa, tocheck) cerr << 1+pa.first << " " << 1+pa.second << endl;
	rep(i,1,n) if(tocheck[i].second > tocheck[i-1].second) fail();
	cout << ans << endl;
}