#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2222;
const int mod1 = 1e9 + 409;
const int mod2 = 1e9 + 433;
typedef long long lint;
using pi = pair<lint, lint>;

int n, m;
char str1[MAXN][MAXN];
char str2[MAXN][MAXN];
lint ps1[MAXN][MAXN];
lint ps2[MAXN][MAXN];
lint pwr1[400500];
lint pwr2[400500];

vector<lint> partial_hash(int x, int y){
	vector<lint> v;
	for(int i=x-m+1; i<=x; i++){
		lint p1 = ps1[i][y] - ps1[i][y-m] * pwr1[m] % mod1 + mod1;
		lint p2 = ps2[i][y] - ps2[i][y-m] * pwr2[m] % mod2 + mod2;
		p1 %= mod1;
		p2 %= mod2;
		v.push_back(p1 * mod2 + p2);
	}
	return v;
}

int main(){
	pwr1[0] = pwr2[0] = 1;
	for(int i=1; i<400500; i++){
		pwr1[i] = pwr1[i-1] * 257 % mod1;
		pwr2[i] = pwr2[i-1] * 257 % mod2;
	}
	scanf("%d %d",&n,&m);
	for(int i=1; i<=n; i++){
		scanf("%s", str1[i] + 1);
	}
	for(int i=1; i<=m; i++){
		scanf("%s", str2[i] + 1);
	}
	for(int i=1; i<=m; i++){
		for(int j=1; j<=n; j++){
			ps1[i][j] = ps1[i][j-1] * 257 + str2[i][j];
			ps2[i][j] = ps2[i][j-1] * 257 + str2[i][j];
			ps1[i][j] %= mod1;
			ps2[i][j] %= mod2;
		}
	}
	map<vector<lint>, int> mp;
	for(int j=1; j<=n-m+1; j++){
		mp[partial_hash(m, j + m - 1)] = j;
	}
	memset(ps1, 0, sizeof(ps1));
	memset(ps2, 0, sizeof(ps2));
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			ps1[i][j] = ps1[i][j-1] * 257 + str1[i][j];
			ps2[i][j] = ps2[i][j-1] * 257 + str1[i][j];
			ps1[i][j] %= mod1;
			ps2[i][j] %= mod2;
		}
	}
	for(int j=1; j<=n-m+1; j++){
		auto fuck = partial_hash(j + m - 1, m);
		if(mp.find(fuck) != mp.end()){
			printf("%d %d\n", j, mp[fuck]);
			return 0;
		}
	}
}