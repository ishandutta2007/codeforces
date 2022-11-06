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

ll cx[(int)1e6+1], c1[(int)1e6+1];

int main(){
	int n;
	cin >> n;
	vi ps(n);
	rep(i,0,n){
		scanf("%d", &ps[i]);
		--ps[i];
	}

	auto add = [&](int b, int a, int fr, int to){
		cx[fr] += a;
		c1[fr] += b;
		cx[to] -= a;
		c1[to] -= b;
	};
	rep(i,0,n){
		int x = ps[i];
		int r1 = (x+n-i)%n;
		int r2 = n-i;
		if(i <= x){
			add(x-i, -1, 0, r1);
			add(i-x, 1, r1, r2);
			add(r2+x, -1, r2, n);
		} else if(i > x){
			add(i-x, 1, 0, r2);
			add(r1, -1, r2, r1);
			add(-r1, 1, r1, n);
		}
	}

	ll a = 0, b = 0;
	vector<ll> cost(n);
	rep(i,0,n){
		a += cx[i];
		b += c1[i];
		cost[i] = a*i + b;
	}
	pair<ll,ll> ans(1LL<<60, -1);
	rep(i,0,n) ans = min(ans, {cost[i], i});
	cout << ans.first << ' ' << ans.second << endl;
}