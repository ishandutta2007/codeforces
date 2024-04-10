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

int n, m, k, x, l, r, cnt[5];
int main () {
    #ifdef LOCAL
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    #endif
    set < pair < pii, int > > S[5], a, b;
    cin >> n >>x;
    for(int i = 0; i < n; i++){
        cin >> k >> l >> r;
        S[k].insert(mp(mp(l, r), i));
    }
    a = S[0];
    b = S[1];
    k = 0;
    l = x;
    int d =  0;
    while( 1 ){
        r = -1;
        set < pair <pii, int > > :: iterator it1;
        for(set < pair <pii, int > > :: iterator it = S[k].begin(); it != S[k].end(); it++){
            if( it->f.f <= x) {
                if( it -> f . s >= r){
                    it1 = it;
                    r = it->f.s;
                }  
            }
        }
        if( r == -1) break;
        x += r;
        S[k].erase(it1);
        cnt[d]++;
        k = 1-k;
    } 
    k = 1;
    x = l;
    S[0] = a;
    S[1] = b;
    d= 1;
    while( 1 ){
        r = -1;
        set < pair <pii, int > > :: iterator it1;
        for(set < pair <pii, int > > :: iterator it = S[k].begin(); it != S[k].end(); it++){
            if( it->f.f <= x) {
                if( it -> f.s >= r){
                    it1 = it;
                    r = it->f.s;
                }  
            }
        }
        if( r == -1) break;
        x+=r;
        S[k].erase(it1);
        cnt[d]++;
        k = 1-k;
    } 
    cout << max(cnt[0], cnt[1]);
    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}