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

struct UF {
	vi t;
	int comps;
	UF(int n){
		t.resize(n,-1);
		comps = n;
	}

	int find(int a){
		return t[a]<0 ? a : t[a]=find(t[a]);
	}

	void uni(int a, int b){
		a = find(a), b = find(b);
		if(a == b) return;
		--comps;
		if(t[a]<t[b]) swap(a,b);
		t[b] += t[a];
		t[a] = b;
	}
};

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	UF uf(m);

	vi a(m);
	trav(x, a) cin >> x;

	int t = 1<<n;

	vi div(t, -1);
	rep(i,0,m) div[a[i]] = i;

	rep(m,0,t) if(div[m] >= 0)
		rep(j,0,n) div[m | (1<<j)] = div[m];

	trav(x, a) x = (t-1)-x;
	vi mul(t, -1);
	rep(i,0,m) if(div[a[i]]>=0){
		uf.uni(div[a[i]], i);
		mul[a[i]] = i;
	}
	rrep(m,0,t) if(mul[m] >= 0 && div[m] >= 0){
		rep(j,0,n) if(m & (1<<j)){
			int m2 = m - (1<<j);
			if(div[m2]>=0){
				mul[m2] = mul[m];
				uf.uni(mul[m], div[m2]);
			}
		}
	}

	cout << uf.comps << endl;	
}