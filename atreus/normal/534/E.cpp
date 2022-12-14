/**
 *    author:  Atrues
 *    created: 27.01.2019 15:55
**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 2e5 + 10;
int occ[maxn], a[maxn], my[maxn];
int n, m;

ll solve(){
	ll x = 0;
	int st = 1, en = 1, dir = +1;
	for (int i = 1; i <= m; i++){
		my[en] ++;
		if (i == m)
			break;
		x += abs(a[en] - a[en + dir]);
		en += dir;
		if (en == n)
			dir = -1;
		if (en == 1)
			dir = +1;
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++){
		if (occ[i] == my[i])
			cnt ++;
	}
	ll len = -1;
	for (int i = 1; i <= n; i++){
		if (cnt == n){
			if (len == -1)
				len = x;
			else
				if (len != x)
					return -2;
		}
		if (my[st] == occ[st])
			cnt --;
		my[st] --;
		if (my[st] == occ[st])
			cnt ++;
		st ++;
		x -= abs(a[st] - a[st - 1]);
		
		en += dir;
		if (my[en] == occ[en])
			cnt --;	
		my[en] ++;
		if (my[en] == occ[en])
			cnt ++;
		x += abs(a[en] - a[en - dir]);
		if (en == n)
			dir = -1;
		if (en == 1)
			dir = +1;
	}
	return len;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	cin >> m;
	for (int i = 0; i < m; i++){
		int x;
		cin >> x;
		occ[x] ++;
	}
	ll ans2 = solve();
	if (ans2 == -2)
		return cout << -1 << endl, 0;
	reverse(a + 1, a + n + 1);
	reverse(occ + 1, occ + n + 1);
	memset(my, 0, sizeof my);
	ll ans1 = solve();
	if (ans1 == -2)
		return cout << -1 << endl, 0;
	if (ans1 == -1)
		cout << ans2 << endl;
	else if (ans2 == -1)
		cout << ans1 << endl;
	else if (ans1 != ans2)
		cout << -1 << endl;
	else
		cout << ans1 << endl;
}