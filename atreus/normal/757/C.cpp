#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int maxn = 1e6 + 10;
const int mod = 1e9 + 7;

vector<int> s[maxn];
int fac[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		int g;
		cin >> g;
		while (g --){
			int x;
			cin >> x;
			s[x].push_back(i);
		}
	}
	sort(s + 1, s + m + 1);
	fac[0] = 1;
	for (int i = 1; i <= m; i++)
		fac[i] = 1ll * fac[i - 1] * i % mod;
	int answer = 1;
	int cnt = 1;
	for (int i = 1; i <= m; i++){
		if (i == m or s[i] != s[i+1]){
			answer = 1ll * answer * fac[cnt] % mod;
			cnt = 1;
		}
		else
			cnt ++;
	}
	cout << answer << endl;
}