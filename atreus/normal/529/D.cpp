#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int maxn = 2e5 + 10;
const int mod = 1e9 + 9;
const int base = 11;

int a[maxn];
int c[maxn];

int get(string s){
	return 10 * (int)(s[0] - '0') + (int)(s[1] - '0');
}

int get_int(string s){
	return get(s.substr(6, 2)) + 60 * get(s.substr(3, 2)) + 60 * 60 * get(s.substr(0, 2));
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, m, t;
	cin >> n >> m >> t;
	for (int i = 0; i < n; i++){
		string s;
		cin >> s;
		a[i] = get_int(s);
	}
	for (int i = 0; i < n; i++){
		int j = lower_bound(a, a + n, a[i] + t) - a;
		if (j - i >= m){
			for (int x = i; x < i + m; x ++)
				c[x] = x - i + 1;
			for (int x = i + m; x < n; x++){
				int p = lower_bound(a, a + n, a[x] - t + 1) - a;
				if (x - p + 1 <= m or c[x - 1] - c[p] + 1 < m)
					c[x] = c[x - 1] + 1;
				else
					c[x] = c[x - 1];
			}
			for (int x = i - 1; x >= 0; x--){
				int p = lower_bound(a, a + n, a[x] + t) - a - 1;
				if (p - x + 1 <= m or c[p] - c[x + 1] + 1 < m)
					c[x] = c[x + 1] - 1;
				else
					c[x] = c[x + 1];
			}
			int mnm = 1 - *min_element(c, c + n);
			cout << c[n - 1] + mnm << endl;
			for (int i = 0; i < n; i++)
				cout << c[i] + mnm << '\n';
			return 0;
		}
	}
	cout << "No solution\n";
}