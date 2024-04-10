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
#include <ext/rope> 
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
using namespace __gnu_cxx;

int n;
int a[2000100];
int N = 2000100;
void solve(){
	scanf("%d", &n);
	for(int i = 0, x; i < n; i++){
		a[i] = i+1;
	}
	int x = 0;
	for(int i = 2; i <= n; ++i){
		a[(x+n) % N] = a[(x+n/i*i) % N];
		for(int j = n/i*i - i; j >= 0; j-=i){
			a[(x+j+i) % N] = a[(x+j) % N];
		}
		x++;
	}
	for(int i = 0; i < n; i++){
		printf("%d ", a[(x+i)%N]);
	}
	
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