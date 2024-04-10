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

char c[1111][1111];
int used[1111];
int cnt = 0, cc;
int n, m;
void solve(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%s", c[i] + 1);
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(c[i][j] == '*'){
				if(!used[i]) cnt++;
				used[i] = 1;
				cc++;
			}
		}
	}
	if(cnt == 0) {
		printf("YES\n1 1\n");
		return;
	}
	if(cnt == 1){
		for(int i = 1; i <= n; i++){
			if(used[i]){
				printf("YES\n%d 1\n", i);
				return;
			}
		}
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++){
			if(c[i][j] == '*'){
				int ok = 0, ind;
				for(int jj = 1; jj <= m; jj++)
					used[jj] = 0;
				for(int ii =1; ii <= n; ii++){
					if(i == ii) continue;
					for(int jj=1; jj <= m; jj++){
						if(c[ii][jj] == '*') {
							if(!used[jj]) {
								ok++;
								ind = jj;
							}
							used[jj] = 1;
						}
					}
				}
				if(ok == 0){
					printf("YES\n%d %d\n", i, 1);
					return;
				}
				
				if(ok == 1){
					printf("YES\n%d %d\n", i, ind);
					return;
				}
				ok = 0;
				ind = 1;
				
				for(int jj = 1; jj <= n; jj++)
					used[jj] = 0;
				for(int ii =1; ii <= n; ii++){
					for(int jj=1; jj <= m; jj++){
						if(j == jj) continue;
						if(c[ii][jj] == '*') {
							if(!used[ii]) {
								ok++;
								ind = ii;
							}
							used[ii] = 1;
						}
					}
				}
				if(ok < 2){
					printf("YES\n%d %d\n", ind, j);
					return;
				}
				printf("NO\n");
				return;
			}
		}
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