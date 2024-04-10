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
char c[300100];
bool calc(int l, int r){
	for(int i = 1; i <= (r-l+1) && l + i * 2 <= r; i++){
		if(c[l] == c[i + l] && c[l] == c[i*2 +  l]) return 1;
	}
	return 0;
}
void solve(){
	scanf("%s", c);
	n = strlen(c);
	ll ans = 0;
	for(int r = 0; r < n; r++){
		int good = 0;
		for(int l = r; l >= 0; l--){
			good |= calc(l, r);
			if(good) {
				ans += l + 1;
				//cout << l << " " << r << "\n";
				break;
			}	
		} 
	}
	cout << ans << "\n";
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