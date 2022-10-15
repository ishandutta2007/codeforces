#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".dat", "r", stdin); freopen(x ".sol", "w", stdout);
#define MAX 100000
#define ms(x) memset(x, 0, sizeof(x));
#define input freopen("input.txt", "r", stdin);
#define ll long long
#define ld long double
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const ld E = 1e-9;

int main() {

	sync;

	int n;
	cin >> n;

	ll ar[n];
	for(int i = 0; i < n; i++)
		cin >> ar[i];

	ll ans = 0;

	sort(ar, ar + n);

	int a = 0;

	for(int i = n - 1; i > 0; i--){
		if(ar[i] <= ar[i - 1] + 1){
			if(a == 0){
				a = ar[i - 1];
			}else{
				ans += a * ar[i - 1];
				a = 0;
			}
			i--;
		}
	}

	cout << ans;


}