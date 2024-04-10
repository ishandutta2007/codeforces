#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 10;

int main(){
	ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc --){
		int n, k;
		cin >> n >> k;
		int answer = 0;
		if (n < k){
			answer += (k - n);
			n = k;
		}
		n -= k;
		if (n & 1)
			answer++;
		cout << answer << '\n';
	}
}