#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

const int maxn = 2e5 + 10;

map<int,ll> mp;

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		int x;
		cin >> x;
		int y = x - i;
		mp[y] += x;
	}
	ll answer = 1;
	for (auto it : mp)
		answer = max(answer, it.second);
	cout << answer << endl;
}