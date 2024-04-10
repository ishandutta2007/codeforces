#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll maxn = 5e5 + 10;
const ll mod = 998244353;

int s[maxn];

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, A, B;
	cin >> n >> A >> B;
	for (int i = 1; i <= n; i++)
		cin >> s[i];
	sort(s + 2, s + n + 1);
	int S = 0;
	for (int i = 1; i <= n; i++)
		S += s[i];
	int cnt = 0;
	int ptr = n;
	while (1LL * A * s[1] < 1LL * B * S) {
		cnt ++;
		S -= s[ptr--];
	}
	cout << cnt << '\n';
}