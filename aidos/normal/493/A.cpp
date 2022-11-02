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

int y[3][101], x[3][101];
int get(char h){
    if( h == 'h') return 0;
    return 1;
}

vector < pair < string, pii > > v;

bool cmp(pair < string, pii >  a, pair < string, pii >  b){
    if( a.s.s<b.s.s) return 1;
    return 0;
}

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    string a, b;
    cin >> a >> b;
    int n;
    cin >> n;
    for(int i = 0;  i<n; i++){
        int t;
        cin >> t;
        char h;
        cin >> h;
        int m;
        cin >> m;
        char r;
        cin >> r;
        int prev = x[get(h)][m];
        if( r == 'r')
            x[get(h)][m]+=2;
        else x[get(h)][m] += 1;
        if( prev < 2 && x[get(h)][m] > 1) {
            if( get(h) == 1){
                cout << b << " " << m << " "<< t << endl;
            }
            else {
                cout << a<< " " << m << " "<< t << endl;
            }
        }
    }


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}