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

const int inf = (1 << 29) - 1;
const int maxn = (int)1e5 + 10; //maximum + 10
const int mod = (int) 1e9 + 7;
using namespace std;

int n, k;
void out(int f, int s) {
	for(int i = 1; i <= n; i++) {
		if(i == f || i == s) putchar('b');
		else putchar('a');
	}
	putchar('\n');
}
void solve(){
	cin >> n >> k;
	for(int i = n-1; i >= 1; i--) {
		int s = n - i;
		if(s >= k) {
			out(i, n-k+1);
			break;
		}else {
			k -= s;
		}
	}
}
int main () {

	int t = 1;
	scanf("%d", &t);
	for(int i=1; i<=t; i++){
		//printf("Case #%d: ", i);
		solve();
	}
    return 0;
}