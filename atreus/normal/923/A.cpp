#include <iostream>

using namespace std;
const int maxn = 1e6 + 100;
int p[maxn], dp[maxn];

int main (){
	int x;
	cin >> x;
	for (int i = 2; i <= 1e6; i++){
		if (!p[i])
			for (int j = i + i; j <= 1e6; j += i){
				p[j] = 1;
				dp[j] = max (dp[j], i);
			}
	}
	int minn = x - dp[x] + 1;
	int ans = 1e9;
	for (int i = minn; i <= x; i++)
		ans = min (ans, i - dp[i] + 1);
	cout << ans << endl;
}