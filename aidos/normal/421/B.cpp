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
#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define pll pair < ll, ll >
#define forit(s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()
#define Vint vector < int >
#define Vll vector < ll >
#define Vb vector < bool >
#define Vpii vector < pii >
#define Vpll vector < pll >

const int inf = (1ll << 31) - 1;

#define MAXN (int) (1e7)
using namespace std;

bool in(char a){
	if(a =='M' || a == 'A' || a == 'H' || 'I' == a || 'O' == a || a == 'T' || a == 'U' || a == 'V' || a == 'W' || a == 'X' || a == 'Y')
		return 0;
	return 1;

}
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    string s;
    cin >> s;
    int n = s.size();
    for(int i = 0; i<n; i++){
    	if(s[i] != s[n-i-1] || in(s[i])){
    		cout << "NO\n";
    		return 0;
    	}
    }
    cout << "YES\n";
    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	#endif
    return 0;
}