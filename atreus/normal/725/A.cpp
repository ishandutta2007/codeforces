#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 5e5 + 10;

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	string s;
	cin >> n >> s;
	int fi = -1, se = -1;
	for (int i = 0; i < n; i++)
		if (s[i] == '<')
			fi = i;
	for (int i = n - 1; i >= 0; i--)
		if (s[i] == '>')
			se = i;
	if (fi == -1 or se == -1 or fi < se)
		return cout << n << endl, 0;
	cout << n - (fi - se + 1) << endl;
}