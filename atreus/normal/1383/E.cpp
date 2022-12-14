#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 20;
const int mod = 1e9 + 7;

int a[maxn], b[maxn], dp[maxn], go[maxn];
bool good[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	int n = 0, cnt = 0;
	for (int i = 0; i < (int)s.size(); i++){
		cnt ++;
		if (i == (int)s.size() - 1 or s[i] != s[i+1]){
			a[++n] = cnt;
			cnt = 0;
		}
	}
	good[s.size()-1] = 1;
	for (int i = s.size() - 2; i >= 0; i--){
		if (s[i] != s[i+1])
			break;
		good[i] = 1;
	}
	int now = 0;
	for (int i = 1; i <= n; i++){
		for (int j = now; j < now + a[i]; j++)
			b[j] = a[i];
		now += a[i];
	}
	int nex = -1;
	dp[s.size()] = 1;
	stack<int> st;
	ll sum = 0;
	for (int i = (int)s.size() - 1; i >= 0; i--){
		if (s[i] == '1'){
			dp[i] = 1;
			if (nex != -1)
				dp[i] = (dp[i] + dp[nex]) % mod;
			nex = i;
			int mxm = 0;
			if (s.back() == '0')
				dp[i] = (dp[i] + a[n]) % mod;
			dp[i] = (dp[i] + sum) % mod;
/*			for (int j = i+1; j < (int)s.size(); j++){
				if (s[j] == '1')
					continue;
				if (good[j]){
					dp[i] = (dp[i] + b[j]) % mod;
					break;
				}
				int nex = j+b[j];
				if (b[j] <= mxm)
					continue;
				dp[i] = (dp[i] + 1ll*dp[nex]*(b[j]-mxm)) % mod;
				mxm = b[j];
			}
*/		}
		else{
			if (good[i])
				continue;
			go[i] = nex;
			while (!st.empty() and b[i] >= b[st.top()]){
				int now = st.top();
				st.pop();
				sum = (sum - 1ll*dp[go[now]]*b[now]%mod + mod) % mod;
				if (!st.empty())
					sum = (sum + 1ll*dp[go[st.top()]]*b[now]) % mod;
			}
			sum = (sum + 1ll*dp[go[i]]*b[i]) % mod;
			if (!st.empty())
				sum = (sum - 1ll*dp[go[st.top()]]*b[i]%mod + mod) % mod;
			st.push(i);
		}
	}
	if (n == 1 and s[0] == '0')
		return cout << s.size() << endl, 0;
	for (int i = 0; i < s.size(); i++)
		if (s[i] == '1')
			return cout << 1ll * dp[i] * (i+1) % mod << endl, 0;
}