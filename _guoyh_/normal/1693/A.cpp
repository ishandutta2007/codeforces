# include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 200051;
int t, n;
ll a[MAXN], s[MAXN];
int main(){
	ios::sync_with_stdio(false);
	cin >> t;
	while (t--){
		cin >> n;
		bool flag = true;
		bool flag1 = false;
		for (int i = 1; i <= n; i++){
			cin >> a[i];
			s[i] = s[i - 1] + a[i];
			if (flag1 && a[i] != 0) flag = false;
			if (s[i] < 0) flag = false;
			if (s[i] == 0) flag1 = true;
		}
		if (flag && s[n] == 0) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}