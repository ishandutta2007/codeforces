#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll maxn = 1e5 + 10;
const ll mod = 1e9 + 7;

int a[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int tc;
	cin >> tc;
	while (tc --){
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		int cnt = 1;
		a[n-1] ++;
		for (int i = n-2; i >= 0; i--){
			if (a[i] == a[i+1])
				continue;
			if (a[i+1] == a[i]+1)
				cnt++;
			else if (a[i+1] > a[i]+1){
				a[i]++;
				cnt++;
			}
		}
		cout << cnt << '\n';
	}
}