#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 10;

ll par[maxn];

bool cmp(ll a, ll b, ll A, ll B){ // a / b <= A / B 
	return 1ll * a * B <= 1ll * A * b;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> par[i];
		par[i] += par[i - 1];
	}
	vector<pair<int,int> > v;
	for (int i = 1; i <= n; i++){
		int a = i, b = i;
		while (!v.empty()){
			auto it = v.back();
			int A = it.first, B = it.second;
			v.pop_back();
			if (cmp(par[b] - par[a - 1], b - a + 1, par[B] - par[A - 1], B - A + 1)){
				a = A;
				continue;
			}
			v.push_back(it);
			break;
		}
		v.push_back({a, b});
	}
	for (auto it : v){
		int x = it.first, y = it.second;
		for (int j = x; j <= y; j++)
			cout << fixed << setprecision(10) << 1. * (par[y] - par[x - 1]) / (y - x + 1) << '\n';
	}
}