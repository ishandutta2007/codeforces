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

int n, m;
char c[500][500];
char d[500][500];

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif

    cin >> m >> n;
    for(int i = 0; i < n; i++)
    	scanf("%s\n", &c[i]);
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
			d[i][j] = c[j][m - 1 - i];
	for(int i =0; i < m; i++){
		for(int j = 0; j < n; j++){
			c[i][j] = d[m - i - 1][j];
		}
	}
	string ss = "";
	for(int i = 0; i < 2 * m; i++){
		int x = i/2;
		for(int j = 0; j < n; j++){
			ss += c[x][j];
			ss += c[x][j];
		}
		ss += '\n';
	}	
	cout << ss;


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}