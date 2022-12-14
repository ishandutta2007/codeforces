#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef long double ld;
 
const int maxn = 500 + 10;

int l[maxn], r[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> l[i] >> r[i];
	int k;
	cin >> k;
	for (int i = 1; i <= n; i++)
		if (r[i] >= k)
			return cout << n - i + 1 << endl, 0;
}