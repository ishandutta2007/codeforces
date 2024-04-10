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
#include <unordered_map>

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

const int inf = 100100;
const int maxn = (int) 1e5 + 10;
const int mod = (int) 1e9 + 7;
using namespace std;
int n, m;
char c[111][111];
int u[111][111];
set<char> S;
void upd(int x, int y) {
	if(x>0 && u[x-1][y]) S.insert(c[x-1][y]);
	if(y>0 && u[x][y-1]) S.insert(c[x][y-1]);
	if(x+1<n && u[x+1][y]) S.insert(c[x+1][y]);
	if(y+1<m && u[x][y+1]) S.insert(c[x][y+1]);
}
void solve(){
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(u[i][j] == 1) continue;
			int k = j;
			while(k < m && u[i][k] == 0) k += 1;
			int len = min(n-i, k - j);
			char D = 'A';
			S.clear();
			for(int x=i; x < i+len; x++) {
				for(int y = j; y < j + len; y++) {
					upd(x, y);
				}
			}
			while(S.count(D)) D = D + 1;
			if(D == 'A') {
			
			}else if(D == 'B'){
				if(i == 0) {
					len = 1;
					S.clear();
					upd(i, j);
				}
				else if(c[i-1][j] != 'A' && j + 1 < m && c[i-1][j + 1] != 'A') {
					len = 1;
					S.clear();
					upd(i, j);
				}
			}
			else{
				len = 1;
				S.clear();
				upd(i, j);
			}
			D = 'A';
			while(S.count(D)) D = D + 1;
			for(int x=i; x < i+len; x++) {
				for(int y = j; y < j + len; y++) {
					c[x][y] = D;
					u[x][y] = 1;
				}
			}
		}
	}
	for(int i = 0; i <n; i++) cout << c[i] << "\n";
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