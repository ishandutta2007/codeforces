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

string a, b;

int n;

string  go(string x){
    int l = 0;
    int r = x.size() - 1;
    if( r % 2 == 0) return x;
    string a1 = "";
    string a2 = "";
    int mid = ( l + r) >> 1;
    for(int  i= 0; i <= mid; i++){
        a1 += x[i];
    }
    a1 = go(a1);

    for(int  i= mid+1; i <= r; i++){
        a2 += x[i];
    }
    a2 = go(a2);
    if(a1 < a2) return a1 + a2;
    return a2 + a1;
}





int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> a >> b;
    n = a.size();
    string a1 = go(a);
    string a2 = go(b);
//    cout << a1 << " "<< a2 << endl;
    if( a1 == a2) cout << "YES\n";
    else cout  << "NO\n";




    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}