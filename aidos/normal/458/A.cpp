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
#define ull unsigned long long
#define pll pair < ll, ll >
#define forit(s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()

const int inf = (1ll << 31) - 1;

#define MAXN (int) (1e7)
using namespace std;
char c[111000];
char t[111000];
int a[511000];
int b[511000];
int main () {
    ios_base::sync_with_stdio(false);
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    scanf("%s", &c);
    scanf("%s", &t);
    int n = strlen(c);
    int m = strlen(t);
    reverse(c, c+n);
    reverse(t, t+m);
    for(int i = 0; i < n; i++){
        a[i] = c[i] - '0';
    }
    for(int i = 0; i < m; i++) b[i] = t[i]-'0';
    m *= 3;
    n *= 3;
    int k = n/3;
    while( k > 0){
        if( a[k]> 0 && a[k-1] > 0) {
            a[k+1] += 1;
            a[k] -= 1;
            a[k-1] -= 1;
            k+=2;
        } 
        else {
            k--;
        }
    }
    k = m/3;
    while( k > 0){
        if( b[k] > 0&& b[k-1] >0) {
            b[k+1] += 1;
            b[k] -= 1;
            b[k-1] -= 1;
            k+=2;
        } 
        else {
            k--;
        }
    }
    while( n > 0 && a[n-1] == 0){
        n--;
    } 
    while( m > 0 && b[m-1]== 0){
        m--;
    }
    if( n < m){
        cout << '<';
        return 0;
    }

    if( n > m){
        cout << '>';
        return 0;
    }
    for(int i = n - 1; i >= 0; i--){
        if( a[i] > b[i]){
            cout << '>';
            return 0;
        }
        if( b[i] > a[i] ){
            cout << '<';
            return 0;
        }
    }
    cout << '=';



    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}