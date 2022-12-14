#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef complex<long double> point;

const int maxn = 2e5 + 10;

int w[maxn], pre[maxn], suf[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n, l, r, Ql, Qr;
	cin >> n >> l >> r >> Ql >> Qr;
	for (int i = 1; i <= n; i++){
		cin >> w[i];
		pre[i] = pre[i-1] + w[i] * l;
	}
	for (int i = n; i >= 1; i--)
		suf[i] = suf[i+1] + w[i] * r;
	int answer = (int)2e9;
	for (int i = 0; i <= n; i++){
		int dL = max(0, (i-1) - (n-i));
		int dR = max(0, (n-i-1) - (i));
		answer = min(answer, pre[i] + suf[i+1] + dL * Ql + dR * Qr);
	}
	cout << answer << '\n';
}