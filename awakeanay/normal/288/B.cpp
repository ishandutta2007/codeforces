#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

#define int long long
#define MOD 1000000007

signed main() {
	int n, k;
	std::cin >> n >> k;
	
	int ans = 1;
	for(int i = 1; i <= n-k; i++)
		ans = (ans * (n-k))%MOD;
	for(int i = 1; i < k; i++)
		ans = (ans * k)%MOD;
		
	std::cout << (ans)%MOD << std::endl;
}