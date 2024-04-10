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

const int maxk = 1000 + 2;
const int maxt = 40;
const int inf = 1e9;
const int mod = 7340033;

long long dp[maxt][maxk];
long long a[maxk];

int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
	int q, t, d, k;
	t = 32;
	for (int i = 0; i <= t; i++)
		dp[i][0] = 1;
	for (int i = 1; i <= t; i++){
		memset(a, 0, sizeof(a));
		for (int i1 = 0; i1 < maxk; i1++)
			for (int i2 = 0; i1 + i2 < maxk; i2++)
				a[i1 + i2] += dp[i - 1][i1] * dp[i - 1][i2];
		for (int j = 0; j < maxk; j++)
			a[j] = a[j] % mod;
		for (int j = 1; j < maxk; j++)
			for (int i1 = 0; i1 < j; i1++)
				dp[i][j] = (dp[i][j] + a[i1] * a[j - 1 - i1]) % mod;	
	}
	/*				for (int j = 1; j < maxk; j++)
			for (int i1 = 0; i1 < j; i1++)
				for (int i2 = 0; i1 + i2 < j; i2++)
		
					for (int i3 = 0; i1 + i2 + i3 < j; i3++){
						cnt++;
						i4 = j - 1 - i1 - i2 - i3;
						dp[i][j] = (dp[i][j] + ((((dp[i - 1][i1] * dp[i - 1][i2]) % mod) * dp[i - 1][i3]) % mod) * dp[i - 1][i4]) % mod;
					}*/
	cerr << "1\n";
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 50; j++)
			epr("%lld ", dp[i][j]);
		epr("\n");
	}
					
	scanf("%d", &q);
	for (int i = 0; i < q; i++){
		scanf("%d%d", &d, &k);
		int cnt = 0;
		for (; d > 1 && (d - 1) % 2 == 0; d = (d - 1) / 2, cnt++);
// 		cerr << cnt << endl;
		cout << dp[cnt][k] << endl;
	}
 
 
    return 0;
}