#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2e5 + 10;

int a[maxn], p[maxn], pos[maxn];
char c[maxn];

int main(){
	ios_base::sync_with_stdio (false);
	int n, k;
	cin >> n >> k;
	k --;
	for (int i = 1; i <= n; i++){
		cin >> p[i];
//		position[p[i]] = i;
	}
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		pos[a[i]] = i;
	}
	for (int i = 1; i <= n; i++)
		a[pos[p[i]]] = i;
	int now = 0;
	int mxm = 1;
	string s;
	for (int i = 1; i <= n; i++){
		mxm = max(mxm, a[i]);
		s += (char)(now + 'a');
		if (mxm == i)
			now = min(now + 1, k);
	}
	if ((int)(s.back() - 'a') == k){
		for (int i = 0; i < n; i++)
			c[p[i + 1]] = s[i];
		cout << "YES\n";
		for (int i = 1; i <= n; i++)
			cout << c[i];
		cout << '\n';
		return 0;
	}
	cout << "NO\n";
}