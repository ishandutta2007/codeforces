#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll maxn = 5e5 + 10;
const ll mod = 998244353;

pair<int,int> c[maxn];

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, x1, x2;
	cin >> n >> x1 >> x2;
	for (int i = 1; i <= n; i++) {
		cin >> c[i].first;
		c[i].second = i;
	}
	sort(c + 1, c + n + 1);
	for (int i = 1; i <= n; i++) {
		int t = (x1 + c[i].first - 1) / c[i].first;
		if (n - i + 1 < t + 1)
			continue;
		int nex = i + t;
		int T = (x2 + c[nex].first - 1) / c[nex].first;
		if (n - nex + 1 < T)
			continue;
		cout << "Yes\n";
		cout << t << " " << T << '\n';
		for (int j = i; j < i + t; j++)
			cout << c[j].second << " ";
		cout << '\n';
		for (int j = nex; j < nex + T; j++)
			cout << c[j].second << " ";
		cout << '\n';
		return 0;
	}
	swap(x1, x2);
	for (int i = 1; i <= n; i++) {
		int t = (x1 + c[i].first - 1) / c[i].first;
		if (n - i + 1 < t + 1)
			continue;
		int nex = i + t;
		int T = (x2 + c[nex].first - 1) / c[nex].first;
		if (n - nex + 1 < T)
			continue;
		cout << "Yes\n";
		cout << T << " " << t << '\n';
		for (int j = nex; j < nex + T; j++)
			cout << c[j].second << " ";
		cout << '\n';
		for (int j = i; j < i + t; j++)
			cout << c[j].second << " ";
		cout << '\n';
		return 0;
	}
	cout << "No\n";
}