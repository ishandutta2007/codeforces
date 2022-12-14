#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2e5 + 10;

int a[maxn];

int main(){
	ios_base::sync_with_stdio (false);
	int n;
	cin >> n;
	string s;
	cin >> s;
	int s1 = 0, n1 = 0, s2 = 0, n2 = 0;
	for (int i = 0; i < n / 2; i++){
		if (s[i] == '?')
			n1 ++;
		else
			s1 += (int)(s[i] - '0');
	}
	for (int i = n / 2; i < n; i++){
		if (s[i] == '?')
			n2 ++;
		else
			s2 += (int)(s[i] - '0');
	}
	int mn = min(n1, n2);
	n1 -= mn;
	n2 -= mn;
	if (n1 > 0 and s2 - s1 == 9 * (n1 / 2))
		return cout << "Bicarp\n", 0;
	if (n2 > 0 and s1 - s2 == 9 * (n2 / 2))
		return cout << "Bicarp\n", 0;
	if (n1 == 0 and n2 == 0 and s1 == s2)
		return cout << "Bicarp\n", 0;
	cout << "Monocarp\n";
}