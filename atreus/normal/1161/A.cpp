#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 1e5 + 5;
const int mod = 998244353;

int a[maxn], last[maxn], first[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= k; i++){
		cin >> a[i];
		last[a[i]] = i;
	}
	for (int i = k; i >= 1; i--)
		first[a[i]] = i;
	int answer = 0;
	for (int i = 1; i <= n; i++){
		for (int j = -1; j <= 1; j++){
			int x = i, y = i + j;
			if (y == 0 or y == n + 1)
				continue;
			int idx1 = first[x];
			int idx2 = last[y];
			if (idx1 == 0)
				answer ++;
			else if (idx2 < idx1)
				answer ++;
		}
	}
	cout << answer << endl;
}