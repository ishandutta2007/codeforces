#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const int mod = 1e9 + 7;
const int maxn = 5e5 + 10;

int a[maxn], b[maxn], pos[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++){
		cin >> b[i];
		pos[b[i]] = i;
	}
	int mx = 0, cnt = 0;
	for (int i = 1; i <= n; i++){
		if (mx > pos[a[i]])
			cnt ++;
		mx = max(mx, pos[a[i]]);
	}
	cout << cnt << endl;
}