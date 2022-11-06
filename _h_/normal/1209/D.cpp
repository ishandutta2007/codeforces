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
	int c;
	UF(int n){
		t.resize(n, -1);
		c = n;
	}
	int find(int a){
		return t[a]<0 ? a : t[a] = find(t[a]);
	}
	void uni(int a, int b){
		a = find(a), b = find(b);
		if(a == b) return;
		--c;
		if(t[a] < t[b]) swap(a,b);
		t[b] += t[a];
		t[a] = b;
	}
};

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	UF uf(n);
	rep(_,0,k){
		int x, y;
		cin >> x >> y;
		uf.uni(x-1,y-1);
	}
	cout << k - (n - uf.c) << endl;
}