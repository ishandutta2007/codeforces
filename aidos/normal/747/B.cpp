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
char c[1111];
string t = "AGCT";
void solve(){
	scanf("%d%s", &n, c);
	if(n % 4 != 0){
		cout <<"===\n";
		return;
	}
	for(int i = 0;  i< 4; i++){
		int x = 0;
		for(int j =0; j < n; j++){
			if(c[j] == t[i]) x++;
		}
		if(x * 4 > n){	
			cout <<"===\n";
			return;
		}
	}
	for(int i = 0;  i< 4; i++){
		int x = 0;

		for(int j =0; j < n; j++){
			if(c[j] == t[i]) x++;
		}
		for(int j =0; j < n; j++){
			if(c[j] == '?'){
				if(x * 4 == n) break;
				c[j] = t[i];
				x++;
			}
		}
	}
	printf("%s\n", c);
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