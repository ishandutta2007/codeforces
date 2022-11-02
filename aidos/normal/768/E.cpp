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

map< vector<int>, int> mov_id;
int cur = 0;
int get(vector<int> x){
	if(mov_id.count(x)) return mov_id[x];
	return mov_id[x] = cur++;
}
int d[66][500100];
int dp[666];
int calc(int y, vector<int> mov){
	sort(all(mov));
	int id=get(mov);
	int &res = d[y][id];
	if(res != -1) return res;
	res = 0;
	set<int> S;
	for(int i = 1; i <= y; i++){
		vector<int> :: iterator it = lower_bound(all(mov), i);
		if(it == mov.end() || *it != i){
			vector<int> z = mov;
			z.pb(i);
			S.insert(calc(y - i, z));
		}
	}
	while(S.count(res)) res++;
	return res;
}
void solve(){
	memset(d, -1, sizeof d);
	vector<int> v;
	for(int i = 1; i <= 60; i++){	
		memset(d, -1, sizeof d);
		mov_id.clear();
		cout << "dp[" << i << "]" << "=" << calc(i, v) << ";\n";
	}
}

void precalc(){
	dp[1]=1;
dp[2]=1;
dp[3]=2;
dp[4]=2;
dp[5]=2;
dp[6]=3;
dp[7]=3;
dp[8]=3;
dp[9]=3;
dp[10]=4;
dp[11]=4;
dp[12]=4;
dp[13]=4;
dp[14]=4;
dp[15]=5;
dp[16]=5;
dp[17]=5;
dp[18]=5;
dp[19]=5;
dp[20]=5;
dp[21]=6;
dp[22]=6;
dp[23]=6;
dp[24]=6;
dp[25]=6;
dp[26]=6;
dp[27]=6;
dp[28]=7;
dp[29]=7;
dp[30]=7;
dp[31]=7;
dp[32]=7;
dp[33]=7;
dp[34]=7;
dp[35]=7;
dp[36]=8;
dp[37]=8;
dp[38]=8;
dp[39]=8;
dp[40]=8;
dp[41]=8;
dp[42]=8;
dp[43]=8;
dp[44]=8;
dp[45]=9;
dp[46]=9;
dp[47]=9;
dp[48]=9;
dp[49]=9;
dp[50]=9;
dp[51]=9;
dp[52]=9;
dp[53]=9;
dp[54]=9;
dp[55]=10;
dp[56]=10;
dp[57]=10;
dp[58]=10;
dp[59]=10;
dp[60]=10;
}

void solve2(){
	int n;
	scanf("%d", &n);
	int res = 0;
	for(int i = 1, x; i <= n; i++){
		scanf("%d", &x);
		res ^= dp[x];
	}
	if(res == 0) printf("YES\n");
	else printf("NO\n");
}

int main () {
	#ifdef LOCAL
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	#endif
    int t=1;
    precalc();
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve2();
    }

    return 0;
}