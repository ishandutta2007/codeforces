#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;

int a[maxn], par[maxn], dif[2*maxn];
map<int,int> mp;

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		mp[a[i]] ++;
	}
	int x = a[1];
	for (int i = 1; i <= n; i++)
		if (mp[a[i]] > mp[x])
			x = a[i];
	for (int i = 1; i <= n; i++)
		par[i] = par[i-1] + (a[i] == x);
	int answer = 0;
	for (int i = 1; i <= min(n,100); i++){
		if (i == x)
			continue;
		memset(dif, -1, sizeof dif);
		int now = 0;
		dif[0+n] = 0;
		for (int j = 1; j <= n; j++){
			now += (a[j] == i);
			if (dif[par[j]-now+n] != -1)
				answer = max(answer, j-dif[par[j]-now+n]);
			else
				dif[par[j]-now+n] = j;
		}
	}
	cout << answer << '\n';
}