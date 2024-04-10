/***
  * Virtual Contest: Forethought Future Cup - Elimination Round
***/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 1e5 + 10;

int a[maxn], x[maxn], par[maxn], b[maxn], sum[maxn];
char s[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < q; i++){
		cin >> s[i] >> x[i];
		if (s[i] == '<' and x[i] > 0){
			x[i] = -x[i] + 1;
			b[i] = 1;
		}
		if (s[i] == '>' and x[i] < 0){
			x[i] = -x[i] - 1;
			b[i] = 1;
		}
	}
	par[q] = maxn + 10;
	for (int i = q - 1; i >= 0; i--){
		par[i] = min(par[i + 1], abs(x[i]));
		sum[i] = sum[i + 1] + b[i];
	}
	
	for (int i = 0; i < n; i++){
		int lo = -1, hi = q;
		while (hi - lo > 1){
			int mid = (lo + hi) >> 1;
			if (par[mid] >= abs(a[i]))
				hi = mid;
			else
				lo = mid;
		}
		int sign;
		if (a[i] >= 0)
			sign = 1;
		else
			sign = -1;

		if (lo == -1){
			if (sum[0] & 1)
				sign *= -1;
		}
		else{
			if (s[lo] == '<')
				sign = 1;
			else
				sign = -1;
			if (sum[hi] & 1)
				sign *= -1;
		}
//		cout << "# " << lo << " - " << sum[hi] << " ";
		cout << abs(a[i]) * sign << " ";
	}
	cout << endl;
}