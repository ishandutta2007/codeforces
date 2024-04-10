//#pragma GCC optimize(2)
// Happy TLE and WA every day!
// by: zxb the vegetable chicken
#include<bits/stdc++.h>
#define mp              make_pair
#define rep(i,n)        for(int i = 0; i < n; i++)
#define foreach(i,c)    for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define BINF            0x7fffffff
#define INF             0x3f3f3f3f
#define LINF            4557430888798830399
#define pb              push_back
#define F               first
#define S               second
#define Time            clock()/CLOCKS_PER_SEC
//#define usingFiles
using namespace std;

typedef unsigned int ui;
typedef pair<int, int> pii;
typedef long long ll;

inline bool Read(int& x){
	x = 0;
	int c;
	int sign = 1;
	while( (c = getchar()) < '0' || c > '9' ) if(c == '-') sign = -1;
	x = c ^ '0';
	while( (c = getchar()) >= '0' && c <= '9' ) x = (x<<3) + (x<<1) + (c ^ '0');
	x *= sign;
	return 1;
}

inline bool Write(int x){
	if(x >= 10) Write(x / 10);
	putchar(x % 10 + '0');
	return 1;
}

const int rp = 666666;
const bool debug = 1;
const bool I_good_vegetable_a = 1;
const int Mod = 1000000007;

ll dp[200200][3];
int num[3];
int n, l, r;

signed main(){
	ios::sync_with_stdio(false);
	#ifdef usingFiles
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	cin >> n >> l >> r;
	num[0] = r/3 - (l-1) / 3;
	num[1] = (r+2) / 3 - (l+1) / 3;
	num[2] = (r+1) / 3 - l/3;
	dp[0][0] = num[0];
	dp[0][1] = num[1];
	dp[0][2] = num[2];
	rep(i, n - 1){
		rep(j, 3){
			rep(k, 3){
				dp[i + 1][(j + k) % 3] += dp[i][j] * num[k];
				dp[i + 1][(j + k) % 3] %= Mod;
			}
		}
	}
	cout << dp[n - 1][0];
	return 0;
}