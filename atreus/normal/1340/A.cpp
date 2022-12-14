#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;

int a[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc --){
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++){
			int x;
			cin >> x;
			a[x] = i;
		}
		bool refresh = 1;
		int m = n;
		string ans = "YES";
		for (int i = 1; i <= n; i++){
			if (refresh == 0){
				if (a[i] != a[i-1] + 1){
					ans = "NO";
					break;
				}
				if (a[i] == m){
					refresh = 1;
					m = n - i;
					continue;
				}
			}
			else{
				if (a[i] == m){
					refresh = 1;
					m = n - i;
					continue;
				}
				refresh = 0;
			}
		}
		cout << ans << '\n';
	}
}