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
#include <bitset>

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
double dp[101][101][101];
int u[101][101][101];

double get(int x, int y, int z) {
	if(x < 0 || y < 0 || z < 0) return 0;
	if(x == 0) return 0;
	if(y + z == 0) return 1;
	double &res = dp[x][y][z];
	if(u[x][y][z] == 1) return res;
	u[x][y][z] = 1;
	int h = x * y + y * z + x * z;
	res += get(x, y-1, z) * x * y/h;
	res += get(x, y, z-1) * y * z/h;
	res += get(x-1, y, z) * x * z/h;
	return res;
}

void solve(){
	int x, y, z;
	cin >> x >> y >> z;
	printf("%.12lf %.12lf %.12lf", get(x, y, z), get(y, z, x), get(z, x, y));
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