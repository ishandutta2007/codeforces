#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2000 + 10;

map<int, int> occur;
int a[maxn];

int main(){
	ios_base::sync_with_stdio (false);
	int t;
	cin >> t;
	while (t --){
		int a, b, n;
		cin >> a >> b >> n;
		n %= 3;
		if (n == 0)
			cout << a << endl;
		else if (n == 1)
			cout << b << endl;
		else
			cout << (a ^ b) << endl;
	}
}