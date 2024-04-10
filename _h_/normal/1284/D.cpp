// written by _h_
// on 2020 01/04 at 13:05:01
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define all(v) (v).begin(),(v).end()
#define trav(x,v) for(auto &x : v)
#define sz(v) int(v.size())
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

ull hsh(ull x){
	x ^= 120390291ULL;
	x *= 1293231123ULL;
	x ^= (x >> 32);
	return x;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<pii> a(n), b(n);
	rep(i,0,n)
		cin >> a[i].first >> a[i].second >> b[i].first >> b[i].second;

	vector<ull> ws(n);
	ws[0] = 712321ULL;
	rep(i,1,n){
		ws[i] = hsh(ws[i-1]);	
	}

	auto info = [&](vector<pii> &p){
		vector<pii> ls;
		rep(i,0,n){
			ls.emplace_back(p[i].first, -1-i);
			ls.emplace_back(p[i].second, i);
		}
		sort(all(ls));
		ull dead = 0, cur = 0;
		vector<ull> mine(n);
		trav(pa, ls){
			int i = pa.second;
			if(i < 0){
				i += 1;
				i = -i;
				cur += ws[i];
				mine[i] -= dead;
			} else {
				mine[i] += dead + cur;
				dead += ws[i];
				cur -= ws[i];
			}
		}
		return mine;
	};
	
	vector<ull> aa = info(a), bb = info(b);

	cout << (aa == bb ? "YES" : "NO") << endl;
}