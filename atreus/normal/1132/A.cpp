#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int maxn = 1e5 + 10;

int cnt[5];

int main(){
	ios_base::sync_with_stdio(false);
	for (int i = 0; i < 4; i++)
		cin >> cnt[i];
	if (cnt[0] != cnt[3])
		return cout << 0 << endl, 0;
	if (cnt[0] == 0 and cnt[2] > 0)
		return cout << 0 << endl, 0;
	cout << 1 << endl;
}