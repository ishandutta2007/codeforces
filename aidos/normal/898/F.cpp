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
int d[5][1000100];
int pw[5][1000100];
int mod[5];
string ans = "";
char c[1000100];
int n;

bool Pri(int x){
	for(int i = 2; i * i <= x; i++){
		if(x % i == 0) return 0;
	}
	return 1;
}
bool ok(int x, int y, int z){
	if(x > 1 && c[0] == '0') return 0;
	if(y > 1 && c[x] == '0') return 0;
	if(z > 1 && c[x+y] == '0') return 0;
	if(max(x, y) > z) return 0;
	for(int i = 0; i < 4; i++){
		int g1 = d[i][x];
		int g2 = d[i][x+y] - d[i][x] * 1ll * pw[i][y] % mod[i];
		int g3 = d[i][n] - d[i][x+y] * 1ll * pw[i][z] % mod[i];
		if(g2 < 0) g2 += mod[i];
		if(g3 < 0) g3 += mod[i];
		if((g1+g2) % mod[i] != g3) return 0;
	}
	return 1;
}

bool stupidok(int x, int y, int z){
	vector<int> a;
	vector<int> b;
	vector<int> cc;
	for(int i = 0; i < n; i++){
		if(i < x) a.pb(c[i] - '0');
		else if(i < x+y) b.pb(c[i] - '0');
		else cc.pb(c[i] - '0');
	}
	reverse(all(a));
	reverse(all(b));
	reverse(all(cc));
	if(max(x, y) < z){
		a.pb(0);
		b.pb(0);
	}
	int d = 0;
	for(int i = 0; i < max(x, y); i++){
		int cur = d;
		if(i < x) cur += a[i];
		if(i < y) cur += b[i];
		if(cur % 10 != cc[i]) return false;
		d = cur/10;
	}
	return true;
}
void out(int x, int y, int z){
	string ans = "";
	for(int i = 0; i < x; i++){
		ans += c[i];
	}
	ans += '+';
	for(int i = x; i < x + y; i++){
		ans += c[i];
	}
	ans += '=';
	for(int i = x+y; i < n; i++){
		ans += c[i];
	}
	printf("%s\n", ans.c_str());
	exit(0);
}
void solve(){
	scanf("%s", c);
	n = strlen(c);
	mod[0] = 1e9+7;
	mod[1] = 1e9+abs(rand()|(rand() << 15)) % (int(1e8)) + 1;
	mod[2] = 1e8+ abs(rand()|(rand() << 15)) % (int(1e7)) + 1;
	mod[3] = 1e7+ abs(rand()|(rand() << 15)) % (int(1e5)) + 1;
	while(!Pri(mod[2])) ++mod[2];
	while(!Pri(mod[3])) ++mod[3];
	for(int k = 0; k < 4; k++){
		pw[k][0] = 1;
	}
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < 4; j++){
			pw[j][i] = (10ll*pw[j][i-1]) % mod[j];
		}
	}
	for(int i =0; i < n; i++){
		for(int j = 0; j < 4;j ++){
			d[j][i+1] = (d[j][i] *10ll+(c[i] - '0')) % mod[j];
		}
	}
	for(int i = 1; i <= n; i++){
		if(i + i + 1 > n) continue;
		if(i + i + i < n) continue;
		if(ok(n - i - i, i, i)){
			if(stupidok(n-i-i, i, i)){
				out(n-i-i, i, i);
			}
		}
		if(ok(i, n - i - i, i)){
			if(stupidok(i, n-i-i, i)){
				out(i, n-i-i, i);
			}
		}
	}

	for(int i = 2; i <= n; i++){
		if(i + i > n) continue;
		if(i + i - 1 + i - 1 < n) continue;
		if(ok(n - i - i+1, i-1, i)){
			if(stupidok(n-i-i+1, i-1, i)){
				out(n-i-i+1, i-1, i);
			}
		}
		if(ok(i-1, n - i - i+1, i)){
			if(stupidok(i-1, n-i-i+1, i)){
				out(i-1, n-i-i+1, i);
			}
		}
	}

}

int main () {
	#ifdef LOCAL
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	#endif
	srand(time(NULL));
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}