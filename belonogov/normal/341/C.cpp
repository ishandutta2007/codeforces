#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <queue>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)

const int maxn = 2000 + 2;
const int inf = 1e9;
const int p = 1e9 + 7;

int a[maxn];
long long  dp[maxn][maxn];

int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
    int n, cnt = 0, t = 0, k;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++){
		cnt += a[i] == -1;
		t += a[i] != -1 && a[a[i] - 1] == -1;
	}
	k = cnt - t;
	dp[cnt][k] = 1;
	for (int i = cnt; i > 0; i--)
		for (int j = k; j >= 0; j--){
			if (j != 0){
				dp[i - 1][j - 1] = (dp[i - 1][j - 1] + dp[i][j] * (i - j)) % p;
				if (j >= 2)
					dp[i - 1][j - 2] = (dp[i - 1][j - 2] + dp[i][j] * (j - 1)) % p;
			}
			else{
				dp[i - 1][j] = (dp[i - 1][j] + dp[i][j] * i) % p;
			}
		}
// 	for (int i = 0; i < 4; i++, cerr << endl)
// 		for (int j = 0; j < 4; j++)
// 			cerr << dp[i][j] << " " ;
// 	
// 	for (int i = 0; i < k; i++)
// 		ans += (ans + dp[cnt - k][i]) % p;
// // 	for (int i = 0; i < cnt - k; i++)
// 		ans = (ans * (i + 1)) % p;
	
	cout << dp[0][0] << endl;
 
    return 0;
}