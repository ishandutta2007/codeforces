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

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, q;
	cin >> n >> q;

	vi a(n);
	trav(x, a) cin >> x;
	trav(x, a) if(x == 0) x = q+1;

	int lg = 30;

	vector<vi> hopp(lg, vi(n));

	rep(i,0,n) hopp[0][i] = a[i];
	rep(t,1,lg) rep(i,0,n){
		int j = i + (1<<(t-1));
		if(j < n) hopp[t][i] = min(hopp[t-1][i], hopp[t-1][j]);
		else hopp[t][i] = hopp[t-1][i];
	}

	vi lo(q+1,n), hi(q+1, -1);

	rep(i,0,n){
		int j = a[i];
		if(j == q+1) continue;
		lo[j] = min(lo[j], i);
		hi[j] = max(hi[j], i);
	}

	rep(j,1,q+1){
		int fr = lo[j], to = hi[j];
		if(fr >= to) continue;

		int g = 0;
		while((1<<(g+1)) < to-fr) ++g;
		int mi = to - (1<<g);
		int mn = min(hopp[g][fr], hopp[g][mi]);

		if(mn < j){
			cout << "NO" << endl;
			return 0;
		}
	}
	int p = -1;
	rep(i,0,n) if(a[i] == q+1) p = i;
	if(p == -1 && lo[q]==n){
		cout << "NO" << endl;
		return 0;
	} else if(lo[q] == n){
		a[p] = q;
	}
	cout << "YES" << endl;

	int pr = q+1;
	rep(i,0,n){
		if(a[i] == q+1) a[i] = pr;
		pr = a[i];
	}
	rep(i,0,n) if(a[i] != q+1){
		rep(j,0,i) a[j] = a[i];
		break;
	}
	trav(x, a) cout << x << ' ';
	cout << endl;
	return 0;
}