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
ll k, b, n, t;
void solve(){
	cin >> k >> b >> n >> t;
	if(k == 1) {
		ll z = b * n + 1;
		ll cur = t;
		for(int i =0; ;i++){
			if(cur >=z) {
				cout << i << "\n";
				return;
			}
			cur += b;
		}
	}
	ll x = k-1+b;
	ll y = t * k - t + b;
	y/=x;
	while(n>0 && y >= k) {
		n-=1;
		y/=k;
	}
	cout << n << "\n";
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