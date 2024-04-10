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

int n, q;
char c[200200];
int p[100200][26];
string s[5];

char tmp[22], val[22];
bool u[252][252][252];
int dp[252][252][252];
int T;

void upd(int &res, int val) {
	if(res == 0) res = val;
	else res = min(res, val);
}
int check(int x, int y, int z) {
	int &res = dp[x][y][z];
	if(x == 0 && y == 0 && z == 0) return 1;
	if(u[x][y][z]) return res;
	u[x][y][z] = 1;
	res = 0;
	if(x > 0) {
		int c = s[1][x-1] - 'a';	
		int cur = check(x-1, y, z);
		if(cur && p[cur][c]) {
			upd(res, p[cur][c]+1);
		}
	}
	if(y>0){	
		int c = s[2][y-1] - 'a';
		int cur = check(x, y-1, z);
		if(cur && p[cur][c]) {
			upd(res, p[cur][c]+1);
		}
	}
	if(z>0){	
		int c = s[3][z-1] - 'a';
		int cur = check(x, y, z-1);
		if(cur && p[cur][c]) {
			upd(res, p[cur][c]+1);
		}
	}
	return res;
}
void upd1() {
	for(int i = 0; i <= s[2].size(); i++) {
		for(int j = 0; j <= s[3].size(); j++) {
		 u[s[1].size()][i][j] =  0;
		}
	}
}

void upd2() {
	for(int i = 0; i <= s[1].size(); i++) {
		for(int j = 0; j <= s[3].size(); j++) {
		 u[i][s[2].size()][j] =  0;
		}
	}
}

void upd3() {
	for(int i = 0; i <= s[1].size(); i++) {
		for(int j = 0; j <= s[2].size(); j++) {
		 u[i][j][s[3].size()] =  0;
		}
	}
}
void solve(){
	scanf("%d%d", &n, &q);
	scanf("%s", c);
	for(int i = n; i > 0; i--){
		for(int j = 0; j < 26; j++) {
			p[i][j] = p[i+1][j];
		}
		p[i][c[i-1] - 'a'] = i;
	}
	for(int i = 0; i < q; i++) {
		int ind;
		scanf("%s%d", tmp, &ind);
		if(tmp[0] == '-') {
			s[ind].pop_back();
		}
		else {
			scanf("%s", val);
			s[ind] += val[0];
			if(ind == 1) upd1();
			if(ind == 2) upd2();
			if(ind == 3) upd3();
		}
		int res = check(s[1].size(),s[2].size(), s[3].size());
		//cout << res << "\n";
		if(res) {
			printf("YES\n");
		}else {
			printf("NO\n");
		}
	}
	
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