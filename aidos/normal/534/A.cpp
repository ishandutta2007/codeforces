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



int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    int n;
    vector < int > v;
    cin >> n;
    if( n < 3){
    	cout << 1 << endl << 1 << endl;
    	return 0;
    }
    if(n == 3){
    	cout << "2\n1 3\n";
    	return 0;
    }
    for(int i = 2; i<= n; i+=2){
    	v.pb(i);
    }
    for(int  i= 1; i<= n; i+=2){
    	v.pb(i);
    }
    cout << v.size() << endl;
    for(int i = 0; i < v.size(); i++){
    	cout << v[i] << " ";
    }
    cout << endl;



    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}