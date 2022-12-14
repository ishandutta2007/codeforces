#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t --){
		int a, b, c;
		cin >> a >> b >> c;
		int answer = 0;
		for (int i = 0; i <= min(a, b/2); i++)
			answer = max(answer, 3*i + 3*min(b - 2*i, c/2));
		cout << answer << '\n';
	}
}