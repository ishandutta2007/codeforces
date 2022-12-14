#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;

int dp[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t --){
		string s;
		cin >> s;
		int n = s.size();
		string t;
		int cnt = 0;
		for (int i = 0; i < n - 1; i++)
			if (s[i] == ':' and s[i+1] != ':')
				cnt ++;
		if (s[0] != ':')
			cnt ++;
		dp[n] = 0;
		for (int i = n - 1; i >= 0; i--){
			dp[i] = 0;
			if (s[i] == ':')
				continue;
			dp[i] = dp[i+1] + 1;
		}
		for (int i = 0; i < n; i++){
			if ((i == 0 and s[i] != ':') or (s[i-1] == ':' and s[i] != ':')){
				while (dp[i] < 4){
					t += '0';
					dp[i] ++;
				}
				while (i < n and s[i] != ':'){
					t += s[i];
					i ++;
				}
				i --;
				continue;
			}
			if (s[i] == ':' and s[i+1] != ':'){
				t += s[i];
				continue;
			}
			if (i == 0){
				t += "0000";
				cnt ++;
			}
			while (cnt < 8){
				t += ":0000";
				cnt ++;
			}
			if (i + 2 < n)
				t += ':';
			i ++;
		}
		cout << t << endl;
	}
}