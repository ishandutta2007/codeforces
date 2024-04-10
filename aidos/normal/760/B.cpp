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
const int maxn = (int)1e3 + 10; //maximum + 10
const int mod = (int) 1e9 + 7;
using namespace std;

int n, m, k;
ll calc(ll x, ll len) {
	if(x < len) {
		return x * (x+1)/2 + len - x;
	}
	return (x+x-len+1) * len/2;
}
bool can(int x) {
	ll K = m-x-calc(x-1, k-1)-calc(x-1, n-k);
	return K >= 0;
}
void solve(){
	cin >> n >> m >> k;
	int x = m/n;
	while(can(x+1)) x++;
	cout << x << "\n";
}
int main () {

	int t = 1;
	//scanf("%d", &t);
	for(int i=1; i<=t; i++){
		//printf("Case #%d: ", i);
		solve();
	}
    return 0;
}