#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int maxn = (1 << 20) + 10;

int lc(int v){
	return 2*v+0;
}
int rc(int v){
	return 2*v+1;
}

int a[2*maxn], ops[maxn];

void solve(){
	int h, g;
	cin >> h >> g;
	int n = (1<<h)-1, m = (1<<g)-1;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int number = n - m;
	vector<int> candids;
	candids.push_back(1);
	int cnt = 1;
	while (number --){
		int v = candids.back();
		if (v > m){
			candids.pop_back();
			number ++;
			continue;
		}
		while (a[lc(v)] != 0 or a[rc(v)] != 0){
			if (a[lc(v)] > a[rc(v)])
				v = lc(v);
			else
				v = rc(v);
		}
		if (v <= m){
			v = candids.back();
			candids.pop_back();
			candids.push_back(lc(v));
			candids.push_back(rc(v));
			number ++;
			continue;
		}
		v = candids.back();
		ops[cnt ++] = v;
		while (a[lc(v)] != 0 or a[rc(v)] != 0){
			if (a[lc(v)] > a[rc(v)]){
				a[v] = a[lc(v)];
				v = lc(v);
			}
			else{
				a[v] = a[rc(v)];
				v = rc(v);
			}
		}
		a[v] = 0;
	}
	ll sum = 0;
	for (int i = 1; i <= m; i++)
		sum += a[i];
	cout << sum << '\n';
	for (int i = 1; i <= n - m; i++)
		cout << ops[i] << " ";
	cout << '\n';
	for (int i = 1; i <= n; i++)
		a[i] = 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	ll t;
	cin >> t;
	while (t --){
		solve();
	}
}