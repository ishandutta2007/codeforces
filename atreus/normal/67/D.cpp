#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn = 1e6 + 10;
const int inf = 2e9;

int pos[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		int x;
		cin >> x;
		pos[x] = i;
	}
	set<int> s;
	for (int i = 1; i <= n; i++){
		int x;
		cin >> x;
		x = n - pos[x] + 1;
		auto it = s.lower_bound(x);
		if (it != s.end())
			s.erase(it);
		s.insert(x);
	}
	cout << (int)s.size() << '\n';
}