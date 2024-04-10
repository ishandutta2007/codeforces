#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
const int mod = 998244353;

int a[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int cnt = 0;
	int mnm = *min_element(a, a +n), mxm = *max_element(a, a + n);
	for (int i = 0; i < n; i++)
		if (a[i] != mnm and a[i] != mxm)	
			cnt ++;
	cout << cnt << '\n';
}