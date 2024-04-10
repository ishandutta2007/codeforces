# include <bits/stdc++.h>
using namespace std;
const int MAXN = 5005;
int T, n;
int a[MAXN], s[MAXN];
int f[MAXN];
map<int, int> mp;
int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while (T--){
		cin >> n;
		for (int i = 1; i <= n; i++){
			cin >> a[i];
			s[i] = s[i - 1] ^ a[i];
		}
		mp[0] = f[0] - 0;
		for (int i = 1; i <= n; i++){
			f[i] = f[i - 1] + 1;
			if (mp.find(s[i]) != mp.end()) f[i] = min(f[i], mp[s[i]] + i - 1);
			mp[s[i]] = f[i] - i;
		}
		cout << f[n] << '\n';
		mp.clear();
	}
	return 0;
}