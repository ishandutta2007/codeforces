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
vector<int>V[LIM];
int dp_up[LIM], dp_down[LIM], T[LIM]; // maksymalne 1-0
void DFS(int x, int o) {
	if(T[x]) dp_down[x]=1;
	else dp_down[x]=-1;
	for(auto i : V[x]) if(i!=o) {
		DFS(i, x);
		dp_down[x]+=max(dp_down[i], 0);
	}
}
void DFS2(int x, int o) {
	for(auto i : V[x]) if(i!=o) {
		dp_up[i]=max(dp_down[x]-max(0, dp_down[i])+dp_up[x], 0);
		DFS2(i, x);
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	rep(i, n) cin >> T[i];
	rep(i, n-1) {
		int a, b;
		cin >> a >> b; --a; --b;
		V[a].pb(b);
		V[b].pb(a);
	}
	DFS(0, 0);
	DFS2(0, 0);
	rep(i, n) cout << dp_down[i]+dp_up[i] << " ";
	cout << '\n';
}