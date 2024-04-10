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

map < string, int > m;
int t;

string lower(string a){
	string b = "";
	for(int i = 0; i < a.size(); i++)
		b += tolower(a[i]);
	return b;
}

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> t;
    int maxi = 1;
    for(int i = 0; i < t; ++i){
    	string a, b, c;
    	cin >> a >> b >> c;
    	a = lower(a);
    	c = lower(c);

    	m[a] = m[c] + 1;
    	maxi = max(maxi, m[a]);
    }
    cout << maxi+1 << endl;



    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}