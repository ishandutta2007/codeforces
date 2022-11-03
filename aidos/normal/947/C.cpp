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
int a[4000100][2];
int x[4000100];



int sz1 = 2;

void add(int d){
	int v=1;
	for(int i = 30; i >= 0; i--){
		int c = bool(d&(1<<i));
		x[v]++;
		if(a[v][c] == 0) a[v][c] = sz1++;
		v = a[v][c];
	}
	x[v]++;
}
int get(int d){
	int v = 1;
	int num = 0;
	for(int i = 30; i >= 0; i--){
		int c = bool(d&(1<<i));
		x[v]--;
		if(a[v][c] == 0 || x[a[v][c]] == 0) {
			c ^= 1;
			num ^= (1<<i);
		}
		v = a[v][c];
	}
	x[v]--;
	return num;
}
void solve(){
	int n;
	scanf("%d", &n);
	vector<int> d(n);
	for(int i = 0, x;i <n;i++){
		scanf("%d", &x);
		d[i] = x;
	}
	for(int i = 0, x;i <n;i++){
		scanf("%d", &x);
		add(x);
	}
	for(int i = 0; i < n; i++){
		printf("%d ", get(d[i]));
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