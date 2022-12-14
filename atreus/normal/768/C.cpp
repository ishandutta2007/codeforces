#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 1026;
const int mod = 998244353;

int a[maxn], b[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n, k, x;
	cin >> n >> k >> x;
	int m = 0;
	int mnm = 1024, mxm = 0;
	for (int i = 0; i < n; i++){
		int y;
		cin >> y;
		a[y] ++;
		m = max({m, y, y^x});
	}
	while (k --){
		bool num = 0;
		for (int i = 0; i <= m; i++){
			if (a[i] == 0)
				continue;
			int cnt = 0;
			if (num == 0)
				cnt = (a[i]+1) / 2;
			else
				cnt = a[i] / 2;
			
			b[i^x] += cnt;
			b[i] += a[i] - cnt;

			num = (a[i] + num) & 1;
		}
		for (int i = 0; i <= m; i++){
			a[i] = b[i];
			b[i] = 0;
		}
	}
	for (int i = 0; i <= m; i++){
		if (a[i] == 0)
			continue;
		mnm = min(mnm, i);
		mxm = max(mxm, i);
	}
	cout << mxm << " " << mnm << endl;
}