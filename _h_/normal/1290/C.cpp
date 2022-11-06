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

struct UF {
	vi t;
	vector<vi> ch;
	vector<bool> par, flex;
	vi cnt0;
	int ans = 0;
	UF(int n){
		t.resize(n, -1);
		ch.resize(n);
		rep(i,0,n) ch[i].push_back(i);
		par.resize(n);	
		flex.resize(n, true);
		cnt0.resize(n,1);
	}
	int find(int a){
		return t[a] < 0 ? a : t[a] = find(t[a]);
	}
	int cost(int a){
		return flex[a] ? min(cnt0[a], sz(ch[a])-cnt0[a]) :
			sz(ch[a])-cnt0[a];
	}
	void flip(int a){
		trav(v, ch[a]) par[v] = !par[v];
		cnt0[a] = sz(ch[a]) - cnt0[a];
	}
	void uni(int a, int b, bool same){
		bool change = same != (par[a] == par[b]);
		a = find(a), b = find(b);
		if(a == b) return;
		ans -= cost(a) + cost(b);
		if(t[a] < t[b]) swap(a,b);
		if(!flex[a] && flex[b]){
			flex[b] = false;
			if(change){
				flip(b);
			}
		} else if(change){
			flip(a);
		}
		cnt0[b] += cnt0[a];
		trav(x, ch[a]) ch[b].push_back(x);
		ch[a].clear();
		t[b] += t[a];
		t[a] = b;
		ans += cost(b);
	}
	void set(int a, bool val){
		bool dostuff = val != par[a];
		a = find(a);
		ans -= cost(a);
		flex[a] = false;
		if(dostuff){
			flip(a);
		}
		ans += cost(a);
	}
};

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int n, k;
	cin >> n >> k;
	string init;
	cin >> init;
	vector<vi> ls(k);
	trav(v, ls){
		int c;
		cin >> c;
		v.resize(c);
		trav(x, v) cin >> x, --x;
	}
	vector<vi> sl(n);
	rep(i,0,k) trav(j, ls[i]) sl[j].push_back(i);

	UF uf(k);
	rep(i,0,n){
		if(sz(sl[i]) == 1){
			uf.set(sl[i][0], init[i]=='0');
		} else if(sz(sl[i]) == 2){
			int a = sl[i][0], b = sl[i][1];
			uf.uni(a, b, init[i] == '1');
		}
		cout << uf.ans << endl;
	}
}