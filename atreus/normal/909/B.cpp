#include <bits/stdc++.h>

using namespace std;

int sig[2000];

int main(){
	int n;
	cin >> n;
	long long ans = 0;
	for (int i = 0; i < n; i++)
		ans += (n - i) - min(i, n - i);
	cout << ans << endl;
}