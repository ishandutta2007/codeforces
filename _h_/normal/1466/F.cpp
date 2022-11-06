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

struct UF {
	vi t;
	UF(int n){
		t.resize(n, -1);
	}
	int find(int a){
		return t[a] < 0 ? a : t[a] = find(t[a]);
	}
	bool uni(int a, int b){
		a = find(a), b = find(b);
		if(a == b) return false;
		if(t[a] < t[b]) swap(a, b);
		t[b] += t[a];
		t[a] = b;
		return true;
	}
};

const ll md = 1e9+7;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int n, m;
	cin >> n >> m;

	ll t = 1;
	vi ans;

	UF uf(m+1);

	rep(i,0,n){
		int k, x, y;
		cin >> k;
		if(k == 1){
			cin >> x;
			y = 0;
		} else {
			cin >> x >> y;
		}
		if(uf.uni(x, y)){
			ans.push_back(i+1);
			t = t * 2 % md;
		}
	}

	cout << t << " " << sz(ans) << endl;
	trav(x, ans) cout << x << " ";
	cout << endl;
}