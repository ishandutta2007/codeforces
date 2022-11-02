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


char c[555][555];
int a[555][555];
int p[1000200];
int sz[1000200];
int col[1000200];
int n, k;
int cur;
int ans = 0;

int get(int x){
	if(p[x] == x) return x;
	return p[x] = get(p[x]);
}

void merge(int x, int y){
	x = get(x);
	y = get(y);
	if(x == y) return;
	p[x] = y;
	sz[y] += sz[x];
}

void add(int x){
	col[x]++;
	if(col[x] == 1) cur += sz[x];
}
void del(int x){
	col[x]--;
	if(col[x] == 0) cur -= sz[x];
}
int sqr(int l, int r, int k){
	int sum = a[l][r];
	if(l >= k) sum -= a[l-k][r];
	if(r >= k) sum -= a[l][r-k];
	if(l>=k && r >= k) sum += a[l-k][r-k];
	return sum;
}

void solve(){
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++){
		scanf("%s", c[i]);
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			p[i * n + j] = i * n + j;
			if(c[i][j] == '.')
				sz[i * n + j] = 1;
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(c[i][j] == 'X') continue;
			if(i > 0 && c[i-1][j] == '.'){
				int x = (i - 1) * n + j;
				merge(x, i * n + j);
			}
			if(j > 0 && c[i][j-1] == '.'){
				int x = i * n + j - 1;
				merge(x, i * n + j);
			}
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			a[i][j] = 0;
			if(i > 0)a[i][j] += a[i-1][j];
			if(j > 0) a[i][j] += a[i][j-1];
			if(i > 0 && j > 0 ) a[i][j] -= a[i-1][j-1];
			if(c[i][j] == 'X') a[i][j]++;
		}
	}
	for(int i = 0; i + k<= n; i++){
		for(int j = 0; j < n * n; j++){
			col[j] = 0;
		}
		cur = 0;
		for(int j = -1; j <= k; j++){
			for(int t = 0; t <= k; t++){
				if(j == -1 && t == k) continue;
				if(j == k && t == k) continue;
				if(i +j < 0 || i + j >= n) continue;
				if(t >= n) continue;
				add(get((i + j) * n + t));
			}
		}
		int tt = cur + sqr(i + k - 1, k-1, k);
		ans = max(tt, ans);
		for(int j = 1; j+k <= n; j++){
			if(i > 0) {
				del(get((i-1) * n + j-1));
				add(get((i-1) * n + j+k-1));
			}
			if(i + k < n) {
				del(get((i + k) * n + j-1));
				add(get((i+k) *n +j + k - 1));
			}
			if(j > 1){
				for(int t = 0; t < k; t++){
					del(get((i + t) * n + j -2));
				}
			}
			if( j + k < n){
				for(int t = 0; t < k; t++){
					add(get((i + t) * n + j+k));
				}
			}
			tt = cur+sqr(i+k-1, j+k-1, k);
			ans = max(ans, tt);
		}
	}
	printf("%d\n", ans);
}

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif

    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Test case #%d\n", i);
      solve();
    }


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}