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
#include <bitset>

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
const int mod = (int) 1e9 + 7;
using namespace std;
int n, k, p, x, y;
int a[1222];
int b[1222];
void solve(){
	cin >> n >> k >> p >> x >> y;
	int s = 0;
	int z = 0;
	for(int i = 0 ; i < k; i++) {
		cin >> a[i];
		b[i] = a[i];
		s += a[i];
		if(a[i] < y) z++;
	}
	for(int i = k; i < n; i++) {
		int t = min((x - s)/(n-i), p);
		if(2*(z+1) <= n) t = 1;
		a[i] = t;
		b[i] = t;
		s += t;
		if(t<=0||s>x) {
			cout << -1 << "\n";
			return;
		}
		if(t < y) z++;
	}
	sort(b, b + n);
	if(b[n/2] < y) {
		cout << -1 << "\n";
		return;
	}
	for(int i = k; i < n; i++) cout << a[i] << "\n";
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