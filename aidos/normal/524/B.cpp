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
#define forit(s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()

const int inf = (1ll << 31) - 1;
const int maxn = (int) 1e5 + 10;

using namespace std;


int n;
int w[1010];
int h[1010];

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif

    cin >> n;
    int ans = 2000000000;
    for(int i = 0; i < n; i++)
    	cin >> w[i] >> h[i];
	for(int i = 0; i < n; i++){
		if(w[i] < h[i]){
			swap(w[i], h[i]);
		}
	}
	for(int i = 1; i <= 1500; i++){
		bool ok = 1;
		int maxi = 0;
		for(int j = 0; j < n; j++){
			if( w[j] <= i) maxi+=h[j];
			else if(h[j] <= i) maxi += w[j];
			else ok=0;
		}
		if(!ok) continue;
		ans = min(ans, i  * maxi);
	}

	cout << ans << endl;


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}