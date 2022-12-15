#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int maxn = 5e5 + 10;

int dp[(1 << 18) + 5];

int main(){
	ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	for (int i = 0; i < q; i++){
		char type;
		string s;
		cin >> type >> s;
		if (type == '?'){
			int cnt = 0;
			int pw = 1;
			for (int i = s.size() - 1; i >= 0; i--, pw *= 2)
				cnt += (s[i] == '1') * pw;
			cout << dp[cnt] << '\n';
			continue;
		}
		int mask = 0, pw = 0;
		while (!s.empty()){
			int k = (int)s.back();
			s.pop_back();
			if (k & 1)
				mask += (1 << pw);
			pw ++;
		}
		if (type == '+')
			dp[mask] ++;
		else
			dp[mask] --;
	}
}