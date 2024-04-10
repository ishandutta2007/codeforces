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

char a[1011][1011];
int used[1011][1010];
int u[1011][1010];
int n, m;
void solve(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++){
		scanf("%s", a[i]);
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(a[i][j] == 'S'){
				used[i][j] = 1;
			}
		}
	}
	for(int iter = 0; iter < 3; iter++){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				u[i][j] = used[i][j];
				used[i][j] = 0;
			}
		}
			for(int i = 0; i < n; i++){
				int was = 0;
				for(int j = 0; j < m; j++){
					if(a[i][j] == '*') {
						was = 0;
						continue;
					}
					was |= u[i][j];
					used[i][j] |= was;
				}
			}
			for(int i = 0; i<n; i++){
				int was = 0;
				for(int j = m-1; j>=0; j--){
					if(a[i][j] == '*') {
						was = 0;
						continue;
					}
					was |= u[i][j];
					used[i][j] |= was;
				}
			}

			for(int j = 0; j < m; j++){
				int was = 0;
				for(int i = n-1; i >= 0; i--){
					if(a[i][j] == '*') {
						was = 0;
						continue;
					}
					was |= u[i][j];
					used[i][j] |= was;
				}
			}
			for(int j = 0; j < m; j++){
				int was = 0;
				for(int i = 0; i < n; i++){
					if(a[i][j] == '*') {
						was = 0;
						continue;
					}
					was |= u[i][j];
					used[i][j] |= was;
				}
			}
		
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(used[i][j]  && a[i][j] == 'T'){
				cout << "YES";
				return;
			}
		}
	}
	cout << "NO";
}

int main () {
	#ifdef LOCAL
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	#endif
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}