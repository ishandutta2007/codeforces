#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
typedef complex<ld> point;
const int maxn = 3e5 + 5;

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
		if (a[0] > a[n-1])
			cout << "NO\n";
		else
			cout << "YES\n";
	}
}