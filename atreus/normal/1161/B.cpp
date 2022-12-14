#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 1e5 + 10;
const int mod = 998244353;

int nex[maxn], pw[maxn];
ll dp[maxn];
map<int, int> last;

int n;

int distance(int fi, int se){
	if (fi <= se)
		return se - fi;
	return n - fi + se;
}

int main(){
	ios_base::sync_with_stdio(false);
	int m;
	cin >> n >> m;
	pw[0] = 1;
	for (int i = 1; i <= n; i++)
		pw[i] = 2 * pw[i - 1] % mod;
	for (int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		if (a > b)
			swap(a, b);
		dp[a] = (dp[a] + pw[b - a]) % mod;
		dp[b] = (dp[b] + pw[n - b + a]) % mod;
	}
	for (int i = n; i >= 1; i--){
		if (last.count(dp[i]))
			nex[i] = last[dp[i]];
		last[dp[i]] = i;
	}
	for (int i = n; i >= 1; i--)
		if (nex[i] == 0)
			nex[i] = last[dp[i]];
	bitset<maxn> bs;
	for (int i = 1; i < n; i++)
		bs[i] = 1;
	for (int i = 1; i <= n; i++){
		if (last[dp[i]] == i){
			bitset<maxn> tmp;
			tmp.reset();
			int now = nex[i];
			int dis = distance(i, now);
			while (now != i){
				tmp[dis] = 1;
				dis += distance(now, nex[now]);
				now = nex[now];
			}
			bs &= tmp;
//			cout << i << " -> " << tmp << endl;
			now = nex[now];
			int bef = i;
			dis = distance(i, nex[i]);
			while (now != i){
				tmp >>= dis;
				tmp[distance(now, bef)] = 1;
//				cout << now << " -> " << tmp << endl;
				bs &= tmp;
				bef = now;
				dis = distance(now, nex[now]);
				now = nex[now];
			}
		}
	}
	for (int i = 1; i < n; i++)
		if (bs[i])
			return cout << "Yes\n", 0;
	cout << "No\n";
}