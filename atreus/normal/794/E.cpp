#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 3e5 + 10;

int n;
int mx = -1;
int a[maxn], answer[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int cnt, L, R;
	if (n & 1)
		L = n / 2 + 0, R = n / 2 + 2, mx = a[n / 2 + 1], cnt = 1;
	else
		L = n / 2 + 0, R = n / 2 + 1, mx = 0, cnt = 0;
	while (L >= 1){
		mx = max(mx, max(a[L], a[R]));
		answer[cnt] = mx;
		cnt += 2;
		L --;
		R ++;
	}

	if (n & 1)
		L = n / 2 + 0, R = n / 2 + 2, mx = 0, cnt = 0;
	else
		L = n / 2 - 1, R = n / 2 + 2, mx = min(a[L + 1], a[R - 1]), cnt = 1;
	
	while (L >= 1){
		mx = max(mx, max(min(a[L], a[L + 1]), min(a[R], a[R - 1])));
		answer[cnt] = mx;
		cnt += 2;
		L --;
		R ++;
	}
	answer[n - 1] = *max_element(a + 1, a + n + 1);

	for (int i = 0; i < n; i++)
		cout << answer[i] << " ";
}