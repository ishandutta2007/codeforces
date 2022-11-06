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

ll cr[2000][2000];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	ll s;

	cin >> n >> s;
	s *= 2;

	vector<ll> xs(n), ys(n);
	rep(i,0,n){
		cin >> xs[i] >> ys[i];
	}

	rep(i,1,n) rep(j,0,i){
		ll res = xs[i]*ys[j] - xs[j]*ys[i];
		cr[i][j] = res;
		cr[j][i] = -res;
	}

	rep(i,2,n) rep(j,1,i){
		ll a = cr[i][j];
		ll d = s-a;
		ll e = -a-s;
                ll ar;
#define F {ar = cr[j][k] - cr[i][k]; if(ar == d || ar == e) goto foo; ++k;}
		int k = 0;
		while(k+4 <= j){ F F F F }
		while(k < j) F
		continue;
		foo:
		cout << "Yes" << endl;
		cout << xs[i] << ' ' << ys[i] << endl;
		cout << xs[j] << ' ' << ys[j] << endl;
		cout << xs[k] << ' ' << ys[k] << endl;
		return 0;
	}
	cout << "No" << endl;
}