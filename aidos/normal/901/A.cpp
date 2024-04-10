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
int n;
int a[200200];
void out(int v){
	cout << "ambiguous\n";
	int la = 0;
	int sz = 1;
	for(int i = 0; i <= n; i++){
		for(int j = 0; j < a[i]; j++){
			printf("%d ", la);
			sz++;
		}
		la = sz-1;
	}
	int la2 = 0;
	la = 0;
	sz = 1;
	printf("\n");
	for(int i = 0; i <= n; i++){
		if(i == v){
			printf("%d ", la2);
			sz++;
			a[i]--;
		}
		int cur_la = 0;
		for(int j = 0; j < a[i]; j++){
			printf("%d ", la);
			sz++;
			if(j==0) cur_la = sz-1;
			else la2 = sz-1;
		}
		la = cur_la;
	}
	printf("\n");
	exit(0);
}
void solve(){
	scanf("%d", &n);
	for(int i = 0; i <= n; i++){
		scanf("%d", &a[i]);
	}
	for(int i = 1; i <= n; i++){
		if(a[i] > 1 && a[i-1] > 1){
			out(i);
		}
	}
	cout << "perfect\n";
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