#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2e5 + 10;

int a[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		int x;
		cin >> x;
		a[x] ++;
	}
	int lans, rans, ans = 0;
	int L = 1;
	while (L < maxn){
		if (a[L] == 0){
			L ++;
			continue;
		}
		int R;
		int cnt = a[L];
		for (R = L + 1; a[R] > 1; R++)
			cnt += a[R];
		cnt += a[R];
		if (cnt > ans)
			lans = L, rans = R, ans = cnt;
		L = R;
	}
	cout << ans << endl;
	for (int i = rans; i >= lans; i--)
		while (a[i] > 1){
			cout << i << " ";
			a[i] --;
		}
	for (int i = lans; i <= rans; i++)
		if (a[i])
			cout << i << " ";
	cout << endl;
}