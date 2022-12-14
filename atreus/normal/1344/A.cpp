#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef complex<long double> point;

const int maxn = 2e5 + 10;

int a[maxn];
bool mark[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc --){
		int n;
		cin >> n;
		for (int i = 0; i < n; i++){
			cin >> a[i];
			a[i] = ((i + a[i]) % n + n) % n;
			mark[a[i]] = 1;
		}
		bool found = 0;
		for (int i = 0; i < n; i++)
			if (mark[i] == 0)
				found = 1;
		if (found)
			cout << "NO\n";
		else
			cout << "YES\n";
		for (int i = 0; i < n; i++)
			mark[i] = 0;
	}
}