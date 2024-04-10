#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll maxn = 1e6 + 10;
const ll mod = 1e9 + 7;

int main(){
	ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc --){
		int n, k;
		cin >> n >> k;
		int lo, hi;
		bool flag = false;
		for (int i = 1; i <= n; i++){
			int h;
			cin >> h;
			if (i == 1){
				lo = h, hi = h;
				continue;
			}
			else{
				int newlo = max(h,lo-k+1);
				int newhi = min(h+k-1,hi+k-1);
				if (newlo > newhi){
					flag = 1;
				}
				lo = newlo, hi = newhi;
			}
			if (i == n and lo != h)
				flag = true;
		}
		if (flag)
			cout << "NO\n";
		else
			cout << "YES\n";
	}
}