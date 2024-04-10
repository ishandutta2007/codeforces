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
int dp[5][111];
int a[111];

int get(int x, int pos){
	if(pos == n) return 0;
	int &res = dp[x][pos];
	if(res != -1) return res;
	res = get(0, pos + 1) + 1;
	if(x != 2 && (a[pos] >> 1) == 1) res = min(get(2, pos + 1), res);
	if(x != 1 && (a[pos] & 1) == 1) res = min(get(1, pos + 1), res);
	return res;
}

void solve(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	memset(dp, -1, sizeof dp);
	printf("%d\n", get(0, 0));
}

int main () {

    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Test case #%d\n", i);
      solve();
    }

    return 0;
}