#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;

int main(){
	ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	while (q --){
		ll n;
		cin >> n;
		ll lo = 2, hi = n + 1;
		while (hi - lo > 1){
			ll mid = (lo + hi) >> 1;
			if (mid * (mid - 1) / 2 > n - mid)
				hi = mid;
			else
				lo = mid;
		}
		ll bridges;
		ll others;
		if (lo == 2){
			bridges = n - 1;
			others = 0;
		}
		else{
			bridges = n - lo;
			others = lo * (lo - 1) / 2;
		}
		ll answer = bridges + others;
		bridges --;
		others += (lo - 1);
		others = min(others, bridges);
		answer = max(answer, bridges + others);
		cout << answer << endl;
	}
}