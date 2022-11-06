#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <bitset>
#include <random>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <complex>
#include <functional>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> int(a);)
#define all(v) v.begin(),v.end()
#define trav(x, v) for(auto &x : v)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long double ld;

const ll md = 1e9+7;

int n;
vi gpf;

void pfs(int x, vi &res){
	if(x == 1) return;
	if(x == n+1){
		res.push_back(x);
		return;
	}
	int p = gpf[x];
	pfs(x/p, res);
	res.push_back(p);
}

void fail(){
	puts("0");
	exit(0);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	
	vector<bool> pr(n+1);
	gpf.resize(n+1);
	vector<int> rad(n+1), kl(n+2);
	rad[1] = 1;
	rep(i,2,n+1){
		if(!gpf[i]){
			for(int j = i; j <= n; j += i)
				gpf[j] = i;
			pr[i] = 1;
		}
		int p = gpf[i], j = i/p;
		rad[i] = rad[j];
		if(j%p != 0)
			rad[i] *= p;
	}
	rad[1] = n+1;
	int hi = n+2;
	rep(d,2,n){
		int nx = n/d;
		rep(i, nx+1, hi)
			kl[i] = d;
		hi = nx+1;
	}

	vector<int> perm(n+1), pp(n+2), rcnt(n+2), klcnt(n+2);
	vector<int> rseen(n+2), pseen(n+2);
	rep(i,1,n+1){
		cin >> perm[i];
		if(perm[i] == 0)
			rcnt[rad[i]]++;
		else {
			if(rseen[perm[i]]++) fail();
			vi ps, is;
			pfs(rad[perm[i]], ps);
			pfs(rad[i], is);
			if(is.size() != ps.size())
				fail();
			rep(k,0,is.size()){
				if(pp[is[k]] == 0)
					pp[is[k]] = ps[k];
				if(pp[is[k]] != ps[k])
					fail();
			}
		}
	}
	rep(i,2,n+2) if(i == n+1 || pr[i]){
		if(pp[i] == 0)
			++klcnt[kl[i]];
		else {
			if(pseen[pp[i]]++) fail();
			if(kl[i] != kl[pp[i]])
				fail();
		}
	}

	ll ans = 1;
	vector<ll> fs(n+3);
	fs[0] = 1;
	rep(i,1,n+3)
		fs[i] = i * fs[i-1] % md;
	trav(x, rcnt)
		ans = ans * fs[x]%md;// cout << x << endl;
	trav(x, klcnt)
		ans = ans * fs[x]%md;// cout << x << endl;

	cout << ans << endl;
}