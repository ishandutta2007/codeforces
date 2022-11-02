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
int a[100100];
int k;

void solve(){
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		a[i] %= k;
	}
	a[n++] = 0;
	sort(a, a + n);
	n = unique(a, a + n) - a;
	int d = k;
	for(int i = 0; i < n; i++){
		if(a[i] == 0) continue;
		d = __gcd(d, a[i]);
	}
	vector<int> res;
	if(d == 0){
		printf("1\n0\n");
		return;
	}
	for(int i = 0; i < k; i++){
		if(i % d == 0){
			res.pb(i);
		}
	}
	cout << res.size() << "\n";
	for(int i = 0; i < res.size(); i++){
		if(i) printf(" ");
		printf("%d", res[i]);
	}
	cout << "\n";
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