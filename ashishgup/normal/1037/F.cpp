#include<bits/stdc++.h>
#define MAXN 1000010
#define P 1000000007LL
#define ll long long
using namespace std;
int esq[MAXN], dir[MAXN], v[MAXN];
int v1[MAXN];
int tree_max[MAXN], tree_min[MAXN];


ll ans;
void update_max(int u, int pos){
	while(u < MAXN){
		tree_max[u] = max(tree_max[u], pos);
		u += (u & -u);
	}
}

void update_min(int u, int pos){
	while(u < MAXN){
		tree_min[u] = min(tree_min[u], pos);
		u += (u & -u);
	}
}

int query_max(int u){
	int ans = -1;
	while(u){
		ans = max(ans, tree_max[u]);
		u -= (u & -u);
	}
	return ans;
}

int query_min(int u){
	int ans = 1e9;
	while(u){
		ans = min(ans, tree_min[u]);
		u -= (u & -u);
	}
	return ans;
}

set<int> S;
vector<int> S1;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	cin >> n >> k;
	k--;
	for(int i = 0; i < n; i++){
		cin >> v[i];
		S.insert(v[i]);
	}
	for(auto &u : S) S1.push_back(u);
	for(int i = 0; i < n; i++){
		v1[i] = (lower_bound(S1.begin(), S1.end(), v[i]) - S1.begin()) + 1;
	}
	for(int i = 1; i < MAXN; i++) tree_min[i] = n, tree_max[i] = -1;

	for(int i = 0; i < n; i++){
		esq[i] = query_max(MAXN - (v1[i]+1) - 1);
		update_max(MAXN - v1[i] - 1, i);
	}

	for(int i = n-1; i >= 0; i--){
		dir[i] = query_min(MAXN - v1[i] - 1);
		update_min(MAXN - v1[i] - 1, i);	
	}	


	for(int i = 0; i < n; i++){
		int a = i - esq[i] - 1;
		int b = dir[i] - i - 1;
		ll x = (ll)v[i];
		//cout << a << " " << b << endl;
	
		if(a > b) swap(a, b);
		//cout << i << " " << a << " " << b << "\n";
		for(int i = 0; i <= a; i++){
			int l1 = (a - i + k-1)/k;
			if(l1 == 0) l1 = 1;
			int l2 = (a + b - i) / k;
			//cout << l2 - l1 + 1 << endl;
			ans += (x * max(0, l2 - l1 + 1)) % P;
			if(ans >= P) ans -= P;
		}
	}

	cout << ans << "\n";
	return 0;
}