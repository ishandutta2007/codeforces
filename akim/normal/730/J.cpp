#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <cstring>
#include <map>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#define f first
#define s second
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define vi vector <int>
#define ld long double
#define pii pair<int, int>
using namespace std;    
const int N = 103, mod = int(1e9)  + 7;

int n, a[N], b[N];
int dp[3][N][2 * N * N + 3];

int main () {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	for(int i = 1; i <= n; i++){
		scanf("%d", &b[i]);
	}
	int r = N * N;
	memset(dp, -1,sizeof(dp));
	dp[0][0][r] = 0;
	int cur = 1, pre = 0;
	for(int i = 0; i < n; i++){
		memset(dp[cur], -1, sizeof(dp[cur]));
		for(int k = 0; k <= i; k++){
			for(int s = 0; s < 2 * N * N; s++){
				if(dp[pre][k][s] != -1){
					if(dp[cur][k + 1][s + b[i + 1] - a[i + 1]] == -1 || dp[cur][k + 1][s + b[i + 1] - a[i + 1]] > dp[pre][k][s]){
						dp[cur][k + 1][s + b[i + 1] - a[i + 1]] = dp[pre][k][s];
					}
					if(dp[cur][k][s - a[i + 1]] == -1 || dp[cur][k][s - a[i + 1]] > dp[pre][k][s] + a[i + 1])
						dp[cur][k][s - a[i + 1]] = dp[pre][k][s] + a[i + 1];
				}                                                 
			}
		}	
		swap(pre,cur);
	}
	int ans = 0;
	for(int k = 1; k <= n; k++){
		ans = mod;
		for(int s = r; s <= 2 * r; s++){
			if(dp[pre][k][s] != -1){
				ans = min(ans, dp[pre][k][s]);
			}
		}
		if(ans != mod){
			cout << k << " " << ans;
			return 0;
		}
	}
	

return 0;
}