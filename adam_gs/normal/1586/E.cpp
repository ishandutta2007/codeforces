#pragma GCC option("arch=native","tune=native","no-zero-upper") 
#pragma GCC target("avx2","popcnt","rdrnd","bmi2")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=3e5+7;
vector<int>V[LIM], sciezki[LIM];
int F[LIM], odl[LIM], oc[LIM], waga[LIM];
int fnd(int x) {
	if(F[x]==x) return x;
	return F[x]=fnd(F[x]);
}
bool uni(int a, int b) {
	if(fnd(a)==fnd(b)) return false;
	F[fnd(b)]=fnd(a);
	return true;
}
void DFS(int x, int o) {
	for(auto i : V[x]) if(i!=o) {
		odl[i]=odl[x]+1;
		oc[i]=x;
		DFS(i, x);
	}
}
void solve() {
	int n, m;
	cin >> n >> m;
	rep(i, n) F[i]=i;
	rep(i, m) {
		int a, b;
		cin >> a >> b; --a; --b;
		if(uni(a, b)) {
			V[a].pb(b);
			V[b].pb(a);
		}
	}
	DFS(0, 0);
	int q;
	cin >> q;
	rep(i, q) {
		int a, b;
		cin >> a >> b; --a; --b;
		vector<int>A, B;
		while(a!=b) {
			if(odl[a]>=odl[b]) {
				A.pb(a);
				waga[a]^=1;
				a=oc[a];
			} else {
				B.pb(b);
				waga[b]^=1;
				b=oc[b];
			}
		}
		for(auto j : A) sciezki[i].pb(j);
		sciezki[i].pb(a);
		reverse(all(B));
		for(auto j : B) sciezki[i].pb(j);
	}
	int sum=0;
	rep(i, n) sum+=waga[i];
	if(sum==0) {
		cout << "YES\n";
		rep(i, q) {
			cout << sciezki[i].size() << '\n';
			for(auto j : sciezki[i]) cout << j+1 << " ";
			cout << '\n';
		}
		return;
	}
	cout << "NO\n";
	int ans=0;
	rep(i, n) {
		int sum=waga[i];
		for(auto j : V[i]) if(j!=oc[i]) {
			sum+=waga[j];
		}
		ans+=waga[i];
		ans-=sum/2;
	}
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	//cin >> _;
	while(_--) solve();
}