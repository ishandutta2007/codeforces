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
string s;
bool check(int x){
	for(int i = 0; i < n; i++){
		int cur = 5;
		int y = i;
		while(cur > 0){
			if( y >= n || s[y] == '.') break;
			y += x;
			cur--;
		}
		if(cur == 0) return 1;
	}
	return 0;
}

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif

    cin >>n >> s;
    for(int i = 1; i <= n; i++){
    	if(check(i)){
    		cout << "yes\n";
    		return 0;
    	}
    }
    cout << "no\n";




    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}