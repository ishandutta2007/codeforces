#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;

typedef int ll;

const ll Mod = 1000000007LL;
const int N = 1e6 + 10;
const ll Log = 30;

//vector<ll> V[N];
int V[N][23];
int p[N];
ll cnt[N];
ll a[N];
vector<ll> C;
ll cp[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, k;
	cin >> n >> k;
	int dd;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		for(int j = 0; j < i; j++){
			dd = abs(a[i] - a[j]);
			cnt[dd] ++;
			if(p[dd] <= 20){
				V[dd][p[dd] ++] = i;
				V[dd][p[dd] ++] = j;
			}
		}
	}
	/*for(int i = 0; i < N; i++){
		sort(all(V[i]));
		V[i].resize(unique(all(V[i])) - V[i].begin());
	}*/
	for(int i = 1; i < N; i++){
		ll sm = 0;
		for(int j = i; j < N; j += i){
			sm += cnt[j];
			if(sm > 25) break;
		}
		if(sm > 25) continue;
		C.clear();
		for(int j = i; j < N; j += i){
			for(int k = 0; k < p[j]; k++) C.pb(V[j][k]);
		}
		sort(all(C));
		C.resize(unique(all(C)) - C.begin());
		if(C.size() > 10) continue;
		for(auto &x : C) x = a[x] % i;
		for(auto x : C) cp[x] ++;
		sm = 0;
		for(auto x : C){
			if(cp[x]){
				sm += cp[x] - 1;
				cp[x] = 0;
			}
		}
		if(sm <= k) return cout << i << '\n', 0;
	}
	return 0;
}