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
const int mod = (int) 1e9 + 7;
using namespace std;
int n;
int m;
int M;
string s;
int a[555];
int dp[555][555];
int get(int x,int y) {
	int &res = dp[x][y];
	if(x == 0 && y == 0) return 1;
	if(res != -1) return res;
	res = 0;
	if(x > 0 && y > 0) res = (res + get(x-1, y) * 1ll * x % M * 1ll * y % M) % M;
	if(y>1) res = (res + get(x, y-2) * 1ll * (y*(y-1)/2) % M) % M;
	if(x>1) res = (res + get(x-2, y+2) * 1ll * (x*(x-1)/2) % M) % M;
	return res;
}
void solve(){
	cin >> n >> m >> M;
	int ans = 1;
	for(int t = 0; t < m; t++){
		cin >> s;
		int c = 0;
		for(int j = 0; j < n; j++){
			if(s[j] == '1') {
				a[j]++;
				c++;
			}
		}
		if(c != 2) {
			cout << 0 << "\n";
			return;
		}
	}
	int cnt0 = 0, cnt1 = 0;
	for(int i = 0; i < n;i++){
		if(a[i] == 0) cnt0++;
		else if(a[i] == 1) cnt1++;
		else if(a[i] > 2){
			cout << 0 << "\n";
			return;
		}
	}
	if((n-m) * 2 != cnt0 * 2 + cnt1) {
		cout << 0 << "\n";
		return;
	}
	memset(dp, -1, sizeof dp);
	cout<<get(cnt0, cnt1) << endl;
}
int main () {
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}