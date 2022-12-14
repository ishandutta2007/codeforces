#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2e5 + 10;

int a[maxn];

bool check(int fi, int se){
	return (se - fi <= fi);
}

int main(){
	ios_base::sync_with_stdio (false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		a[i] = abs(a[i]);
	}
	sort(a + 1, a + n + 1);
	ll answer = 0;
	for (int i = 1; i <= n; i++){
		int lo = i, hi = n + 1;
		while (hi - lo > 1){
			int mid = (lo + hi) >> 1;
			if (check(a[i], a[mid]))
				lo = mid;
			else
				hi = mid;
		}
		answer += (lo - i);
	}
	cout << answer << endl;
}