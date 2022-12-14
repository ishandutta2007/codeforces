#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef complex<long double> point;

const int maxn = 2e5 + 10;

int mpf[maxn];
vector<int> b[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int m = 2e5;
	for (int i = 2; i <= m; i++)
		if (mpf[i] == 0)
			for (int j = i; j <= m; j += i)
				mpf[j] = i;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		int x;
		cin >> x;
		while (x > 1){
			int t = mpf[x], cnt = 0;
			int y = 1;
			while (mpf[x] == t){
				cnt ++;
				y *= mpf[x];
				x /= mpf[x];
			}
			b[t].push_back(y);
		}
	}
	ll answer = 1;
	for (int i = 2; i <= m; i++){
		if (mpf[i] == i){
			int s = (int)b[i].size();
			if (s <= n - 2)
				continue;
			sort(b[i].begin(), b[i].end());
			if (s == n-1)
				answer *= b[i][0];
			else
				answer *= b[i][1];
		}
	}
	cout << answer << endl;
}