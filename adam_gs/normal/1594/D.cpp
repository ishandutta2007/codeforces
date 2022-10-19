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
const int LIM=2e5+7;
vector<pair<int,int>>V[LIM];
int kol[LIM];
void solve() {
	int n, m;
	cin >> n >> m;
	rep(i, n) {
		V[i].clear();
		kol[i]=-1;
	}
	rep(i, m) {
		int a, b;
		string s;
		cin >> a >> b >> s; --a; --b;
		if(s[0]=='c') {
			V[a].pb({b, 0});
			V[b].pb({a, 0});
		} else {
			V[a].pb({b, 1});
			V[b].pb({a, 1});
		}
	}
	int ans=0;
	rep(i, n) if(kol[i]==-1) {
		queue<int>q;
		int ile[2];
		ile[0]=ile[1]=0;
		q.push(i);
		kol[i]=0;
		while(!q.empty()) {
			int p=q.front(); q.pop();
			++ile[kol[p]];
			for(auto j : V[p]) {
				if(kol[j.st]==-1) {
					kol[j.st]=kol[p]^j.nd;
					q.push(j.st);
				} else if(kol[j.st]!=(kol[p]^j.nd)) {
					cout << -1 << '\n';
					return;
				}
			}
		}
		ans+=max(ile[0], ile[1]);
	}
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}