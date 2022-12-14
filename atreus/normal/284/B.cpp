#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
const int maxn = 5e3 + 100;
int sig[maxn][maxn], dp[maxn][maxn];

int main(){
	int n;
	string s;
	cin >> n >> s;
	int a = 0, b = 0, c = 0;
	for (int i = 0; i < s.size(); i++){
		if (s[i] == 'A')
			a ++;
		else if (s[i] == 'F')
			b ++;
		else
			c ++;
	}
	if (c == 0)
		cout << a << endl;
	else if (c == 1)
		cout << 1 << endl;
	else
		cout << 0 << endl;
}