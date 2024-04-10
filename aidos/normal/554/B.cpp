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

const int inf = (1ll << 25) - 1;
const int maxn = (int) 1e7 + 10;
const int mod = (int) 1e9 + 7;
const int maxd = (int) 700700;
using namespace std;
int n;
char c[122];
int a[122];
vector<int> b[122];
void solve(){
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> c;
		for(int j = 0; j < n; j++) b[i].pb(c[j] - '0');
	}
	sort(b, b + n);
	int ans = 0;
	for(int i = 0; i < n; i++) {
		while(i + ans < n && b[i + ans] == b[i]) ans++;
	}	
	cout  << ans << "\n";
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