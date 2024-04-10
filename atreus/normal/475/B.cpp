#include <iostream>

using namespace std;

const int MOD = 1e9 + 7;
int a[1000 + 500];
int dp[1000 + 500][20000 + 500];

int main (){
	int n, m;
	string a, b;
	cin >> n >> m >> a >> b;
	if (a[0] == '>' && a[n - 1] == '<' && b[0] == '^' && b[m - 1] == 'v')
		return cout << "YES" << endl, 0;
	if (a[0] == '<' && a[n - 1] == '>' && b[0] == 'v' && b[m - 1] == '^')
		return cout << "YES" << endl, 0;
	cout << "NO" << endl;
}