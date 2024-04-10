#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 3e5 + 10;

int main(){
	ios_base::sync_with_stdio(false);
	int a, b, c;
	cin >> a >> b >> c;
	int t = min(a, b);
	int len = c + t;
	a -= t;
	b -= t;
	cout << 2ll * len + (max(a, b) > 0) << endl;
}