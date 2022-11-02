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

int main () {
    #ifdef LOCAL
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    #endif
    string s;
    int k;
    cin >> s >> k;
    for(int i = 0; i< s.size() && k > 0; i++){
    	int pos = i, t = k;
    	for(int j = i+1; j < s.size() && t > 0; j++){
    		if( s[pos] < s[j] ){
    			pos = j;
    		}
    		t--;
    	}
    	if( pos == i) continue;
    	while( pos != i){
    		swap(s[pos], s[pos-1]);
    		pos--;
    		k--;
    	}
    }
    cout << s << endl;
    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	#endif
    return 0;
}