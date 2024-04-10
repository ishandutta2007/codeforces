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

int dp[2020][2020][12];
int used[2020][2020][12];

int T;
int n;
int k;
int a[2020];
int mod = 998244353;
int get(int i, int j, int sum){
	if(i == k){
		return sum == 0;
	}
	int &res = dp[i][j][sum];
	if(used[i][j][sum] == T) return res;
	res = 0;
	used[i][j][sum] = T;
	int pos1 = (k+1)/2 - j;
	if(j + 1 <= (k + 1)/2)
	    res = (res + get(i+1, j+1, (sum + a[i]) % 11) * 1ll * pos1) % mod;
	int x = k/2-i + j;
	if(x > 0)
	    res = (res + get(i + 1, j, (sum - a[i] + 11) % 11) * 1ll * x) % mod;
	return res;
}
int get2(int i, int j, int sum){
	if(i == n){
		return sum == 0;
	}
	int &res = dp[i][j][sum];
	if(used[i][j][sum] == T) return res;
	used[i][j][sum] = T;
	res = 0;
	int cur = i-k;
	int pos1 = (k + 1)/2;
	int pos2 = k + 1 - pos1;
	pos1 += j;
	pos2 += cur- j;

	res = (res + get2(i + 1, j, (sum - a[i] + 11) % 11) * 1ll * pos2) % mod;
	res = (res + get2(i + 1, j+1, (sum + a[i]) % 11) * 1ll * pos1) % mod;
	return res;
}

void solve(){
	scanf("%d", &n);
	std::vector<int> v0, v1;
	for(int i = 0, x; i < n; i++){
		scanf("%d", &x);
		int sum = 0;
		int cnt = 0;
		int sgn = 1;
		while(x > 0){
			sum = (sum + 11 + sgn * (x % 10)) % 11;
			sgn *= -1;
			x/=10;
			cnt++;
		}

		if(cnt % 2){
			v1.pb(sum);
		}
		else {
			v0.pb((11-sum) % 11);
		}
	}
	k = v1.size();
	for(int i = 0; i < k; i++)
		a[i] = v1[i];
	for(int i = 0; i < (int)v0.size(); i++){
		a[i + k] = v0[i];
	}
	int ans = 0;
	T++;
	for(int i = 0; i < 11; i++){
		ans = (ans + get(0, 0, i) * 1ll * get2(k, 0, (11-i) % 11) )% mod;
		//cout << get(0, 0, i) << endl;

	}
	cout << ans << endl;
}

int main () {
    //cout << "Hello world\n";
    int t=1;
    scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}