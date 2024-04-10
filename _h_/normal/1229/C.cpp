// written by aitch
// on 2019 09/23 at 17:44:31
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

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vi deg(n);
	vector<vi> ls(n);
	rep(_,0,m){
		int a, b;
		cin >> a >> b;
		--a, --b;
		++deg[a], ++deg[b];
		if(a < b) swap(a,b);
		ls[b].push_back(a);
	}
	auto calc = [&](int i){
		ll x = sz(ls[i]);
		return x * (deg[i]-x);
	};
	ll cur = 0;
	auto promote = [&](int i){
		cur -= calc(i);
		trav(j, ls[i]){
			cur += deg[j]-1-2*sz(ls[j]);
			ls[j].push_back(i);
		}
		ls[i].clear();
	};
	rep(i,0,n) cur += calc(i);
	cout << cur << endl;
	int q;
	cin >> q;
	rep(_,0,q){
		int v;
		cin >> v;
		promote(v-1);
		cout << cur << endl;
	}
}