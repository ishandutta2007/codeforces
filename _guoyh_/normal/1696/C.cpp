# include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 200051;
int t, n, m, k;
int a[MAXN], b[MAXN];
ll s1[MAXN], s2[MAXN];
int gettyp(int x){
	while (x % m == 0) x /= m;
	return x;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> t;
	while (t--){
		cin >> n >> m;
		for (int i = 1; i <= n; i++){
			cin >> a[i];
			s1[i] = s1[i - 1] + a[i];
		}
		cin >> k;
		for (int i = 1; i <= k; i++){
			cin >> b[i];
			s2[i] = s2[i - 1] + b[i];
		}
		if (n % (m - 1) != k % (m - 1) || s1[n] != s2[k]){
			cout << "No\n";
			continue;
		}
		bool flag = true;
		int pt = 1;
		for (int i = 1; i <= k; i++){
			if (gettyp(a[pt]) != gettyp(b[i])){
				flag = false;
				break;
			}
			while (s1[pt] < s2[i]){
				if (gettyp(a[++pt]) != gettyp(b[i])){
					flag = false;
					break;
				}
			}
			if (!flag) break;
			if (s1[pt] == s2[i]) pt++;
		}
		if (flag) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}