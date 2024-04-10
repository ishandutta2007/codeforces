#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 3e5 + 10;

map<int, bool> mark;
int a[maxn];

int main(){
	ios_base::sync_with_stdio (false);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		mark[a[i]] = 1;
	}
	int q;
	cin >> q;
	while (q --){
		int x;
		cin >> x;
		int answer = k + 1;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= k; j++){
				ll me = 1ll * j * a[i];
				if (me > x)
					break;
				if (me == x)
					answer = min(answer, j);
				for (int p = 1; p <= k - j; p++)
					if ((x - me) % p == 0 and mark.count((x - me) / p))
						answer = min(answer, j + p);
			}
		}
		if (answer == k + 1)
			answer = -1;
		cout << answer << '\n';
	}
}