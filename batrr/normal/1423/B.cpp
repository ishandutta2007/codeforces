#include <stdio.h>
#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()

typedef long long ll;

using namespace std;

const int N = (int)3e5 + 123, mod = (int)1e9 + 7, inf = (int)1e9;
const ll INF = (ll)1e18;

int ans, pr[N], n, m, R, cnt, used[N];
bool ok[N];
vector <pair <int, int> > g[N];

bool kuhn(int v){
	if(used[v] == cnt)
		return 0;
	used[v] = cnt;
	for(auto to : g[v]){
		if(to.s <= R && pr[to.f] == 0){
			pr[to.f] = v;
			return 1;
		}
	}
	for(auto to : g[v]){
		if(to.s <= R && kuhn(pr[to.f])){
			pr[to.f] = v;
			return 1;
		}
	}
	return 0;
}

int get(int x){
	R = x;
	ans = 0;
	for(int i = 1; i <= n; ++i)
		pr[i] = 0, ok[i] = 0;
	for(int i = 1; i <= n; ++i)
		for(auto j : g[i])
			if(j.s <= R && pr[j.f] == 0 && !ok[i])
				pr[j.f] = i, ans++, ok[i] = 1;
	for(int i = 1; i <= n; ++i){
		cnt++;
		if(!ok[i])
			ans += kuhn(i);
	}
	return ans;
}

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	cin >> n >> m;

	for(int i = 1; i <= m; ++i){
		int x, y, z;
		cin >> x >> y >> z;
		g[x].pb(mp(y, z));
	}

	int l = 0, r = (int)1e9;
	int d = get(r);
	if(d != n){
		cout << -1;
		return 0;
	}

	while(l <= r){
		int md = (l + r) >> 1;
		if(get(md) == d){
			r = md - 1;
		}else l = md + 1;
	}

	cout << r + 1;

	return 0;
}