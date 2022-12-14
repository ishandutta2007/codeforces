#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int maxn = 1e5 + 10;

int a[maxn], h[maxn], mx[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	bool found = 0;
	for (int i = 1; i <= n - 1; i++){
		int v, u;
		cin >> v >> u;
		a[v] ++;
		if (u != n)
			found = 1;
	}
	if (found)
		return cout << "NO\n", 0;
	int par = 0;
	for (int i = n; i >= 1; i--){
		if (i == n){
			h[0] = i;
			continue;
		}
		par += a[i];
		if (a[i] > 0)
			h[par] = i;
	}
	par = 0;
	for (int i = 1; i <= n; i++){
		par += a[i];
		if (par > i)
			return cout << "NO\n", 0;
	}
	int ptr = n - 1;
	for (int i = 0; i < n; i++){
		if (h[i] != 0)
			continue;
		while (a[ptr] > 0)
			ptr --;
		h[i] = ptr --;
	}
	cout << "YES\n";
	for (int i = 0; i < n - 1; i++)
		cout << h[i] << " " << h[i + 1] << '\n';
}