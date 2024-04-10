/**
 *    author:  Atreus
**/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 3e5 + 10;
int a[maxn], b[maxn], c[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		int sign = 1;
		if (i & 1)
			sign = -1;
		b[i] = b[i - 1] + sign * a[i];
	}
	for (int i = n; i >= 1; i--){
		int sign = 1;
		if (i & 1)
			sign = -1;
		c[i] = c[i + 1] + sign * a[i];
	}
	int answer = 0;
	for (int i = 1; i <= n; i++){
		int sum = b[i - 1] - c[i + 1];
		answer += (sum == 0);
	}
	cout << answer << endl;
}