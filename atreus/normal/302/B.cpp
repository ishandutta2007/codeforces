#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;

int a[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		int c, t;
		cin >> c >> t;
		a[i] = a[i - 1] + c * t;
	}
	int last = 1;
	while (m --){
		int x;
		cin >> x;
		while (a[last] < x)
			last ++;
		cout << last << '\n';
	}
}