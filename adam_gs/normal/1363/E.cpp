#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define all(a) a.begin(), a.end()
const int LIM=2e5+7;
vector<int>V[LIM];
int mam[LIM], chce[LIM], ojciec[LIM], odw[LIM];
ll ile[LIM][2][2];
pair<ll,int>koszt[LIM];
void znajdz_ojca(int x, int o) {
	ojciec[x]=o;
	for(auto i : V[x]) if(i!=o) znajdz_ojca(i, x);
}
void dodaj(int x, int p) {
	odw[x]=1;
	if(x!=p) {
		ile[p][1][0]+=ile[x][1][0];
		ile[p][0][1]+=ile[x][0][1];
	}
	for(auto i : V[x]) if(i!=ojciec[x] && !odw[i]) {
		dodaj(i, p);
	}
}
void solve() {
	int n;
	cin >> n;
	int sum=0;
	rep(i, n) {
		cin >> koszt[i].st >> mam[i] >> chce[i];
		++ile[i][mam[i]][chce[i]];
		sum+=ile[i][1][0];
		sum-=ile[i][0][1];
		koszt[i].nd=i;
	}
	if(sum) {
		cout << -1 << '\n';
		return;
	}
	rep(i, n-1) {
		int a, b;
		cin >> a >> b; --a; --b;
		V[a].pb(b);
		V[b].pb(a);
	}
	znajdz_ojca(0, 0);
	sort(koszt, koszt+n);
	ll ans=0;
	rep(i, n) if(!odw[koszt[i].nd]) {
		int x=koszt[i].nd;
		dodaj(x, x);
		ll c=min(ile[x][1][0], ile[x][0][1]);
		ans+=c*koszt[i].st*2;
		if(x) {
			ile[x][1][0]-=c;
			ile[x][0][1]-=c;
			ile[ojciec[x]][1][0]+=ile[x][1][0];
			ile[ojciec[x]][0][1]+=ile[x][0][1];
		}
	}
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	//cin >> _;
	while(_--) solve();
}