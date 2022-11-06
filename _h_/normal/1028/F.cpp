#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("arch=corei7-avx")
using namespace std;
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define rrep(i,a,b) for(int i = b; i --> (a);)
#define all(v) v.begin(),v.end()
#define trav(x,v) for(auto &x : v)
#define sz(v) (int)(v).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int gcd(int x, int y){
	x = abs(x), y = abs(y);
	while(y){
		int t = x%y;
		x = y;
		y = t;
	}
	return x;
}

void red(int &x, int &y){
	int d = gcd(x, y);
	x /= d, y /= d;
	if(pii(x, y) < pii(0,0)){
		x *= -1;
		y *= -1;
	}
}

ll tol(int x, int y){
	return (ll(x)<<32) + y;
}

int main(){
	
	int q;
	scanf("%d", &q);

	vi t(q), x(q), y(q);
	rep(i,0,q) scanf("%d%d%d", &t[i], &x[i], &y[i]);

	unordered_map<ll, int> ren;
	ren.reserve(3e5);
	vi ls(q);
	int ix = 0;

	rep(i,0,q) if(t[i] == 3){
		red(x[i], y[i]);
		ll h = tol(x[i], y[i]);
		if(!ren.count(h)){
			ls[i] = ren[h] = ix++;
		} else {
			ls[i] = ren[h];
		}
	}
	vi cur(ix);
	
	map<ll, int> dre;
	int jx = 0;
	rep(i,0,q) if(t[i] != 3){
		ll d = ll(x[i])*x[i] + ll(y[i])*y[i];
		if(!dre.count(d)) dre[d] = jx++;
		ls[i] = dre[d];
	}

	vector<set<pii>> bucks(jx);
	int n = 0;
	int z = 0;
	rep(i,0,q){
		if(t[i] <= 2){
			if(x[i]==0 && y[i]==0){
				z += t[i]==2 ? -1 : 1;
				continue;
			}
			int j = ls[i];	
			if(t[i] == 2) bucks[j].erase(pii(x[i], y[i]));

			int dif = t[i]==2 ? -1 : 1;
			n += dif;
			dif *= 2;
			trav(pa, bucks[j]){
				int a = pa.first + x[i], b = pa.second+y[i];
				if(a==0 && b==0){
					a = -y[i], b = x[i];
				}
				red(a, b);
				ll p = tol(a, b);
				if(ren.count(p)) cur[ren[p]] += dif;
			}
			if(t[i] == 1) bucks[j].insert(pii(x[i], y[i]));
			int a = x[i], b = y[i];
			red(a, b);
			ll p = tol(a,b);
			if(ren.count(p)) cur[ren[p]] += dif/2;
		} else if(t[i] == 3){
			printf("%d\n", n - cur[ls[i]]);
		}
	}
}