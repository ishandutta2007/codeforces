#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
const int mod = 1e9 + 7;
const int maxn = 2e5 + 10;

int a[maxn], b[maxn];

void solve(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	for (int i = 0; i < n; i++)
		cin >> b[i];
	sort(b, b + n);
	for (int i = 0; i < n; i++)
		cout << a[i] << " \n"[i == n-1];
	for (int i = 0; i < n; i++)
		cout << b[i] << " \n"[i == n-1];
}

int main(){
	ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc --){
		solve();
	}
}