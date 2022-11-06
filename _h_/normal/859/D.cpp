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
typedef long double ld;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	int m = 1<<n;
	vector<vi> prob(m, vi(m));
	trav(v, prob) trav(x, v) cin >> x;
	vector<ld> ans(m), lv(m,1), todo(m);
	function<ld(int,int)> calc = [&](int fr, int to){
		if(fr+1 == to) return ld(0);
		int mi = (fr+to)/2;
		ld a = calc(fr, mi), b = calc(mi, to);
		rep(i,fr,mi){
			ld sum = 0;
			rep(j,mi,to) sum += (lv[j]*prob[i][j])/100.;
			todo[i] = lv[i] * sum;
		}
		rep(i,mi,to){
			ld sum = 0;
			rep(j,fr,mi) sum += (lv[j]*prob[i][j])/100.;
			todo[i] = lv[i] * sum;
		}
		rep(i,fr,to) lv[i] = todo[i];
		rep(i,fr,mi) ans[i] += b;
		rep(i,mi,to) ans[i] += a;
		rep(i,fr,to) ans[i] += lv[i]*(mi-fr);
		ld mx = 0;
		rep(i,fr,to) mx = max(mx, ans[i]);
		return mx;
	};
	cout.precision(11);
	cout << calc(0, m) << endl;
}