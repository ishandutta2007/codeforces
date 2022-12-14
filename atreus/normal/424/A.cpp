#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 10;

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	string s;
	cin >> n >> s;
	int a = 0;
	for (int i = 0; i < n; i++)
		if (s[i] == 'x')
			a ++;
	cout << abs(a - n/2) << '\n';
	for (int i = 0; i < n; i++){
		if (a < n / 2 and s[i] == 'X')
			s[i] = 'x', a++;
		if (a > n / 2 and s[i] == 'x')
			s[i] = 'X', a--;
	}
	cout << s << endl;
}