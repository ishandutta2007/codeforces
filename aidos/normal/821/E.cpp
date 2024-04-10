#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <ctime>
#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define ull unsigned long long
#define pll pair < ll, ll >
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()
#define sz(a) (int)a.size()

const int inf = (1ll << 30) - 1;
const int maxn = (int) 1e5 + 10;

using namespace std;

int n;
ll A[111];
ll B[111];
ll C[111];
ll K;
ll dp[22], d[22];
ll a[20][20];
ll b[20][20];

ll c[20][20];
ll mod = 1000 * 1000 * 1000 + 7;
void binpow(ll x){
	for(int i = 0;  i < 16; i++)
		for(int j = 0; j < 16; j++)
			b[i][j] = (i==j);
	while(x > 0){
		if(x & 1){
			for(int i = 0; i < 16; i++){
				for(int j = 0; j < 16; j++){
					c[i][j] = 0;
					for(int k = 0; k < 16; k++){
						c[i][j] = (c[i][j] + a[i][k] * 1ll * b[k][j]) % mod;
					}
				}
			}
			for(int i = 0; i < 16; i++){
				for(int j = 0; j < 16; j++){
					b[i][j] = c[i][j];
				}
			}
		}
		x/=2;
		for(int i = 0; i < 16; i++){
				for(int j = 0; j < 16; j++){
					c[i][j] = 0;
					for(int k = 0; k < 16; k++){
						c[i][j] = (c[i][j] + a[i][k] * 1ll * a[k][j]) % mod;
					}
				}
			}
			for(int i = 0; i < 16; i++){
				for(int j = 0; j < 16; j++){
					a[i][j] = c[i][j];
				}
			}
	}
}
void solve(){
	cin >> n >> K;
	for(int i = 0; i < n; i++)
		cin >> A[i] >> B[i] >> C[i];
	B[n-1] = K;
	dp[0]++;
	for(int i = 0; i < n; i++){
		int t = C[i] + 1;
		for(int j = t; j < 16; j++) dp[j] = 0;
		for(int k = 0; k < 16; k++){
			for(int j = 0; j < 16; j++)
				a[k][j] = 0;
		}
		for(int j = 0; j < t; j++){
			if(j > 0) a[j][j-1]++;
			if(j + 1 < t) a[j][j + 1]++;
			a[j][j]++;
		}
		binpow(B[i] - A[i]);
		for(int x = 0; x < 16; x++){
			d[x] = 0;
			for(int j = 0; j < 16; j++){
				d[x]= (d[x] + b[j][x] * 1ll * dp[j] % mod) % mod;
			}
		}
		for(int x = 0; x < 16; x++)
			dp[x] = d[x];
		for(int x = t; x < 16; x++)
			dp[x] = 0;
	}
	cout << dp[0] << endl;
}

int main () {
    //cout << "Hello world\n";
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}