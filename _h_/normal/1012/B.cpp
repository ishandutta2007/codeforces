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

struct UF {
	vi t;
	int cnt;

	UF(int n){
		t.assign(n, -1);
		cnt = n;
	}

	int find(int a){
		return t[a]<0 ? a : t[a] = find(t[a]);
	}

	void uni(int a, int b){
		a = find(a), b = find(b);
		if(a == b) return;
		--cnt;
		if(t[a] < t[b]) swap(a,b);
		t[b] += t[a];
		t[a] = b;
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, q;
	cin >> n >> m >> q;

	UF uf(n+m);

	rep(_,0,q){
		int r, c;
		cin >> r >> c;
		--r, --c;
		uf.uni(r, c+n);
	}
	cout << uf.cnt-1 << endl;
}