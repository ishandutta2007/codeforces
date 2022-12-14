#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
typedef complex<ld> point;
const int maxn = 1000 + 1;
const int inf = 1e7;

int a[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t --){
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < n; i++)
			if (i & 1)
				cout << -abs(a[i]) << " ";
			else
				cout << abs(a[i]) << " ";
		cout << '\n';
	}
}