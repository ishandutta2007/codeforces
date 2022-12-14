#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int maxn = 5e5 + 10;

int a[maxn], b[maxn];
vector<int> v[maxn];
int x[maxn], f[maxn];

void solve(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d%d", &x[i], &f[i]);
		a[x[i]] ++;
		b[x[i]] += f[i];
	}
	for (int i = 1; i <= n; i++)
		v[a[i]].push_back(b[i]);
	multiset<int> s;
	int fi = 0, se = 0;
	for (int i = n; i >= 1; i--){
		for (auto u : v[i])
			s.insert(-u);
		if (!s.empty()){
			fi += i;
			se += min(i, -(*s.begin()));
			s.erase(s.begin());
		}
	}
	printf("%d %d\n", fi, se);
	// vitex;
	for (int i = 0; i < n; i++){
		a[x[i]] --;
		b[x[i]] -= f[i];
	}
	for (int i = 1; i <= n; i++)
		v[i].clear();
}

int main(){
	int q;
	scanf("%d", &q);
	while (q --){
		solve();
	}
}