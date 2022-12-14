#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef complex<ld> point;
const int maxn = 3e5 + 5;

int p[maxn];
bool mark[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t --){
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> p[i];
		int cnt = 0;
		for (int i = 1; i <= n; i++){
			mark[i] = (p[i] == i);
			cnt += mark[i];
		}
		if (cnt == n){
			cout << 0 << '\n';
			continue;
		}
		int x = 0;
		int i1 = -1, i2 = -1;
		for (int i = 1; i <= n; i++){
			if (i1 == -1 and mark[i] == 0)
				i1 = i;
			if (mark[i] == 0)
				i2 = i;
		}
		for (int i = i1; i <= i2; i++)
			if (mark[i])
				x = 1;
		cout << 1 + x << '\n';
	}
}