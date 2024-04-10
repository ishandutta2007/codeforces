#include <iostream>
#include <queue>

#define int long long

signed main() {
	int dp[10][10][10];
	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 10; j++) {
			for(int k = 0; k < 10; k++)
				dp[i][j][k] = -1;
			dp[i][j][i] = 1;
			dp[i][j][j] = 1;
		}
	}
	
	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 10; j++) {
			std::queue<int> q;
			q.push(i);
			q.push(j);
			while(!q.empty()) {
				int u = q.front(); q.pop();
				if(dp[i][j][(u+i)%10] == -1) {
					dp[i][j][(u+i)%10] = dp[i][j][u]+1;
					q.push((u+i)%10);
				}
				if(dp[i][j][(u+j)%10] == -1) {
					dp[i][j][(u+j)%10] = dp[i][j][u]+1;
					q.push((u+j)%10);
				}
			}
		}
	}
	
	int ans[10][10];
	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 10; j++) {
			ans[i][j] = 0;
		}
	}
	
	std::string s;
	std::cin >> s;
	
	int last = 0;
	for(int k = 1; k < s.length(); k++) {
		int cur = s[k]-'0';
		for(int i = 0; i < 10; i++) {
			for(int j = i; j < 10; j++) {
				if(dp[i][j][(cur-last+10)%10] == -1)
					ans[i][j] = -1;
				else if(ans[i][j] != -1) {
					ans[i][j] += dp[i][j][(cur-last+10)%10]-1;
				}
				ans[j][i] = ans[i][j];
			}
		}
		last = cur;
	}
	
	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 10; j++) {
			std::cout << ans[i][j] << " ";
		}
		std::cout << std::endl;
	}
	
	return 0;
}