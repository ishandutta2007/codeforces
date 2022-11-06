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
	
	int n;
	cin >> n;
	vi as(n), bs(n);
	trav(x, as) cin >> x;
	trav(x, bs) cin >> x;
	vi p(n);
	rep(i,0,n) p[i] = i;
	sort(all(p), [&](int x, int y){
		return bs[x]>bs[y];
	});
	sort(all(as));
	vi ans(n);
	rep(i,0,n) ans[p[i]] = as[i];
	trav(x, ans) cout << x << ' '; cout << endl;
}