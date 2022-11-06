

#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < b; ++i)
#define trav(x, v) for(auto &x : v)
#define all(v) v.begin(), v.end()
#define sz(v) int(v.size())
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<vi> vvi;

const ll md = 998244353;

struct UF {
	vi t, xr;
	int zs = 0;
	UF (int n){
		t.resize(n, -1);
		xr.resize(n);
	}
	void sing(int a){
		a = find(a);
		zs += !xr[a];
		xr[a] = 0;
	}
	int find(int a){
		return t[a] < 0 ? a : t[a] = find(t[a]);
	}
	void uni(int a, int b){
		a = find(a), b = find(b);
		if(a == b){
			++zs;
			return;
		}
		if(t[a] < t[b]) swap(a,b);
		t[b] += t[a];
		t[a] = b;
		if(xr[a] == 0 && xr[b] == 0) ++zs;
		xr[b] *= xr[a];
	}
};

ll solve(){
	string s;
	cin >> s;
	if(s.back() == '1') return 0;
	int m = sz(s);
	int l = m/2 - 1;
	ll mul = 1;
	if(m%2 && s[m/2]=='?') mul = 2;
	vi ss(l, -1);
	for(int i = 1; i < m-1-i; ++i){
		char a = s[i], b = s[m-1-i];
		if(a == '?' && b == '?') mul = mul * 2 % md;
		if(a != '?' && b != '?') ss[i-1] = a != b;
	}
	ll ans = 0;
	rep(k,0,m-1){
		UF uf(l);	
		rep(i,0,l) uf.xr[i] = ss[i]==-1 ? 0 : ss[i]==1 ? -1 : 1;
		int j = min(k, m-1-k);
		if(j && j-1 < l) uf.xr[j-1] *= -1;
		ll cur = 1;
		for(int i = 1; i <= k-i; ++i){
			int ii = min(k-i, m-1-(k-i));
			if(ii==m-1-ii || k-i == i){
				uf.sing(i-1);
			} else {
				uf.uni(i-1, ii-1);
			}
		}
		rep(i,0,l){
			if(uf.find(i) == i && uf.xr[i]==-1){
				cur = 0;
			}
		}
		rep(_,0,uf.zs) cur = cur * 2 % md;
		ans += cur;
	}
	ans %= md;
	return ans * mul;
}

int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	
	ll res = solve();
	res %= md;
	if(res < 0) res += md;
	cout << res << endl;
}