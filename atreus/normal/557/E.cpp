/**
 *    author:  Atreus
 *    created: 12.02.2019
**/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int maxn = 5e3 + 10;
bitset<maxn> dp[maxn];
vector<int> pals[maxn];

int n;
int f[2 * maxn];
string s;

bool mark[maxn];

void kmpfunction(string t){
	memset(mark, 0, sizeof mark);
	int m = t.size();
	string q = t + "#" + s;
	f[0] = 0, f[1] = 0;
	int k = 0;
	for (int i = 2; i <= q.size(); i++){
		while (q[i - 1] != q[k] and k > 0)
			k = f[k];
		k += (q[i - 1] == q[k]);
		f[i] = k;
		if (f[i] == m)
			mark[i - 2 * m - 1] = 1;
	}
}

int occur(string t){
	if (t.size() == 0)
		return 0;
	kmpfunction(t);
	int ret = 0;
	for (int i = 0; i + t.size() - 1 < n; i++){
		if (mark[i] and dp[i][i + t.size() - 1])
			ret ++;
	}
	return ret;
}

int sstr(string t){
	kmpfunction(t);
	int ret = 0;
	for (int i = 0; i < n; i++){
		if (mark[i]){
			int idx = lower_bound(pals[i].begin(), pals[i].end(), i + t.size() - 1) - pals[i].begin();
			ret += pals[i].size() - idx;
		}
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	int k;
	cin >> s >> k;
	n = s.size();

	for (int len = 1; len <= n; len++){
		for (int i = 0; i + len - 1 < n; i++){
			int j = i + len - 1;
			if (len <= 4)
				dp[i][j] = (s[i] == s[j]);
			else
				dp[i][j] = (s[i] == s[j]) * dp[i + 2][j - 2];
			
			if (dp[i][j])
				pals[i].push_back(j);
		}
	}
	string ans;
	while (ans.size() <= n){
		int x = occur(ans);
		if (x >= k)
			return cout << ans << endl, 0;
		k -= x;
		ans += 'a';
		x = sstr(ans);
		if (x >= k)
			continue;
		k -= x;
		ans.pop_back();
		ans += 'b';
	}
}