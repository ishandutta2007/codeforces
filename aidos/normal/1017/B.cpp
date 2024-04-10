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
char t[100100];
char s[100100];
ll a[2][2];
ll get(int x, int y){
	ll cur = 0;
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			if((i|y) != (x|y) || (x|j) != (i|j)){
				//if(i != x || y != j)
					cur += a[i][j];
			}
		}
	}
	return cur;
}
void solve(){
	scanf("%d%s%s", &n, s, t);
	for(int i = 0; i < n; i++){
		a[s[i] - '0'][t[i] - '0']++;
	}
	ll ans = 0;
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			ans += get(i, j) * a[i][j];
		}
	}
	cout << ans/2 << "\n";
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