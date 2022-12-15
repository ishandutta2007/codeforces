#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
const int maxn = 1e6 + 10;
const ll inf = 1e18;

int a[maxn];

ll check(int n, int x){
	ll ret = 0;
	for (int i = 1; i <= n; i++){
		int num = a[i] / (x + 1);
		int rem = a[i] % (x + 1);
		if (rem == 0){
			ret += num;
			continue;
		}
		if (num + rem < x)
			return inf;
		ret += num + 1;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	ll answer = inf;
	int now = 1;
	while (now <= a[1]){
		int lo = now, hi = a[1] + 1;
		while (hi - lo > 1){
			int mid = (lo + hi) >> 1;
			if (a[1] / now == a[1] / mid)
				lo = mid;
			else
				hi = mid;
		}
		int High = hi;
		lo = now - 1;;
		while (hi - lo > 1){
			int mid = (lo + hi) >> 1;
			if (a[1] / mid >= a[1] % mid)
				hi = mid;
			else
				lo = mid;
		}
		for (int i = hi; i < High; i++)
			answer = min(answer, check(n, i));
		now = High;
	}
	cout << answer << endl;
}