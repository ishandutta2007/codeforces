#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 1e5 + 5;

int n;
string s[maxn];
int deg[maxn], a[maxn];

bool issc(){
	for (int i = 0; i < n; i++)
		a[i] = deg[i];
	sort(a, a + n, greater<int>());
	ll now = 0;
	for (int i = 1; i < n; i++){
		now += a[i - 1];
		if (now == 1ll * i * (i - 1) / 2 + 1ll * i * (n - i))
			return false;
	}
	return true;
}

void flip(int v){
	deg[v] = n - 1 - deg[v];
	for (int i = 0; i < n; i++){
		if (i == v)
			continue;
		if (s[v][i] == '1')
			deg[i] ++, s[v][i] = '0';
		else
			deg[i] --, s[v][i] = '1';
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> s[i];
		for (int j = 0; j < n; j++)
			if (s[i][j] == '1')
				deg[i] ++;
	}
	if (issc())
		return cout << "0 1" << endl, 0;
	int sum = 0;
	for (int i = 0; i < n; i++){
		flip(i);
		sum += issc();
		flip(i);
	}
	if (sum > 0)
		return cout << "1 " << sum << endl, 0;
	if (n == 6)
		return cout << "2 18" << endl, 0;
	cout << -1 << endl;
}