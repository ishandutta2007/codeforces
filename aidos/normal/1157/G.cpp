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
int n, m;
int a[222][222];
int b[222][222];
int c[522];
void check(int I) {
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++) b[i][j] = a[i][j], c[j + n] = 0;
		c[i] = 0;
	}
	for(int j = 0; j < I; j++) {
		if(b[0][0] != b[0][j]) c[j+n] = 1;
	}
	for(int j=I; j < m; j++) c[j + n] = b[0][I] ^ b[0][j];
	for(int i = 0; i < n; i++) for(int j=0; j < m; j++) b[i][j] ^= c[i]^c[j+n];
	int ok = 1;
	for(int i = 0; i < n; i++) {
		int need=0;
		int same = 1;
		for(int j=1; j < m; j++) {
			if(b[i][j] < b[i][j-1]) need = 1;
			if(b[i][j] != b[i][j-1]) same = 0;
			
		}
		if(need == 1) {
			c[i] ^= 1;
			ok = 0;
			for(int j = 0; j < m; j++) b[i][j] ^= 1;
		}else if(same){
			if(ok && b[i][0]){
				c[i] ^= 1;			
				for(int j = 0; j < m; j++) b[i][j] ^= 1;
			}else if(!ok && !b[i][0]) {
				c[i] ^= 1;
				for(int j = 0; j < m; j++) b[i][j] ^= 1;
			}
		}else ok = 0;
	}
	vector<int> x;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++) {
			x.pb(b[i][j]);	
		}
	}
	for(int i = 1; i < x.size(); i++) if(x[i] < x[i-1]) return;
	printf("YES\n");
	for(int i = 0; i < n; i++) printf("%d", c[i]);
	printf("\n");	
	for(int i = 0; i < m; i++) printf("%d", c[i + n]);
	printf("\n");
	exit(0);
}

void check2(int I) {
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++) b[i][j] = a[i][j], c[j + n] = 0;
		c[i] = 0;
	}
	for(int j = 0; j < I; j++) {
		if(b[0][0] == b[0][j]) c[j+n] = 1;
	}
	for(int j=I; j < m; j++) c[j + n] = b[0][I] ^ b[0][j];
	for(int i = 0; i < n; i++) for(int j=0; j < m; j++) b[i][j] ^= c[i]^c[j+n];
	int ok = 1;
	for(int i = 0; i < n; i++) {
		int need=0;
		int same = 1;
		for(int j=1; j < m; j++) {
			if(b[i][j] < b[i][j-1]) need = 1;
			if(b[i][j] != b[i][j-1]) same = 0;
			
		}
		if(need == 1) {
			c[i] ^= 1;
			ok = 0;
			for(int j = 0; j < m; j++) b[i][j] ^= 1;
		}else if(same){
			if(ok && b[i][0]){
				c[i] ^= 1;			
				for(int j = 0; j < m; j++) b[i][j] ^= 1;
			}else if(!ok && !b[i][0]) {
				c[i] ^= 1;
				for(int j = 0; j < m; j++) b[i][j] ^= 1;
			}
		}else ok = 0;
	}
	vector<int> x;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++) {
			x.pb(b[i][j]);	
		}
	}
	for(int i = 1; i < x.size(); i++) if(x[i] < x[i-1]) return;
	printf("YES\n");
	for(int i = 0; i < n; i++) printf("%d", c[i]);
	printf("\n");	
	for(int i = 0; i < m; i++) printf("%d", c[i + n]);
	printf("\n");
	exit(0);
}


void solve(){
	scanf("%d%d", &n, &m);
	for(int i= 0; i < n; i++){
		for(int j = 0; j < m; j++) scanf("%d", &a[i][j]);
	}
	for(int i = 0; i <= m; i++) check(i);
	for(int i = 0; i <= m; i++) check2(i);
	printf("NO\n");
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