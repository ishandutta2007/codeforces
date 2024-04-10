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
char c[200200];
int a[200200];
int n;

void check(int l, int r){
	if(l == 0) l++;
	sort(a+l, a + r);
	for(int i = l; i < r; i++){
		if(a[i] - a[i-1] != 1){
			cout << "NO";
			exit(0);
		}
	}
}
void solve(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	scanf("%s", c+1);
	c[0] = '0';
	c[n+1] = '0';
	int last = 0;
	for(int i = 1; i <= n; i++){
		if(c[i] == '0') {
			check(last, i+1);
			last=i+1;
		}
	}
	check(last, n+1);
	cout <<"YES\n";
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