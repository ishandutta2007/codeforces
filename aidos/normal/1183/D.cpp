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
const int mod = (int) 1e9 + 7;
using namespace std;
int n;
int a[200200];
int c[200200];
void solve(){
	cin >> n;
	for(int i = 0; i < n; i++) c[i] = 0;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		c[x-1]++;
	}
	sort(c, c + n);
	int k = 0;
	for(int i = 0; i < n; i++) {
		if(c[i] > k) k++;
	}
	int cur=inf;
	int ans = 0;
	for(int i = n-1; k > 0 && i >= 0; i--) {
		if(c[i] >= k) {
			int d = min(c[i], cur-1);
			ans += d;
			k--;
			cur = d;
		}
	}
	cout<<ans << "\n";
}

int main () {
    int t=1;
    scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}