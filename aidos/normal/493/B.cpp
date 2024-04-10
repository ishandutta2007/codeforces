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
vector < int > v1, v2;
ll sum[5];
int gr(vector < int > a, vector < int > b){
    int k = 0;
    int l = 0;
    while( a.size() > k && b.size() > l && a[k] == b[l]){
        k++;
        l++;
    }
    if( a.size() == k){
        return 0;
    }
    if( b.size() == l) return 1;
    if( a[k] < b[l]) return 0;
    return 1;
}

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> n;
    int last = -1;
    for(int i = 0, x; i < n; i++){
        cin >> x;
        if( x < 0) {
            sum[1] -= x;
            v1.pb( -x);
            last = 1;
        }
        else {
            sum[0] += x;
            v2.pb( x );
            last = 0;
        }
        
    }
    if( sum[0] > sum[1]){
        cout << "first";
        return 0;
    }
    else if( sum[0] < sum[1]){
        cout << "second";
        return 0;
    }
    if(gr(v1, v2)){
        cout << "second";
    }
    else if( gr(v2, v1)){
        cout << "first";
    }
    else if( last ){
        cout << "second";
    }
    else {
        cout << "first";
    }




    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}