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
#include <unordered_map>

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

const int inf = 100100;
const int maxn = (int) 1e6 + 10;
const int mod = (int) 1e9 + 7;
using namespace std;
int a[4020];
int n;
int cnt = 0;
int sum = 0;
void solve(){
	cin >> n;
	for(int i = 0; i < 2*n; i++) {
		int x;
		scanf("%d.%d", &x, &a[i]);
		if(a[i] == 0) cnt++;
		else sum += a[i]; 
	}
	int ans = 1000*2*n;
	for(int i = 0; i <= min(n, 2*n-cnt); i++) {
		int h = n-i;
		if(h > cnt) continue;
		ans = min(ans, abs(sum-1000*i));
	}
	printf("%.3lf\n", ans/1000.0);
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