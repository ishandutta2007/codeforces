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
const int maxn = (int) 1e4 + 10;
const int mod = (int) 1e9 + 7;
using namespace std;
int n, m;
int a[555][555];
void solve(){
	cin >> n >> m;
	
	if(n == 1 && m == 1) {
		cout << 0 << "\n";
		return;
	}
	int bad = 0;
	if(n > m) {
		swap(n, m);
		bad = 1;
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			a[i][j] = 1;
		}
	}
	for(int i = 1; i <= n; i++) {
		int x = i;
		for(int j = 1; j <= m; j++) {
			int t = __gcd(a[i][j], x);
			a[i][j] *= x/t;
		}
	}
	for(int j = 1; j <= m; j++) {
		int x = n + j;
		for(int i = 1; i <= n; i++) {
			int t = __gcd(a[i][j], x);
			a[i][j] *= x/t;
		}
	}
	if(bad) {
		swap(n, m);
	}
	for(int i=1; i <= n; i++) {
		for(int j = 1; j <= m; j++){
			if(!bad)
				cout << a[i][j] << " ";
			else cout << a[j][i] << " ";
			
		}
		cout << "\n";
	}

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