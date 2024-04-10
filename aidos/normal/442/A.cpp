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
int getC(char a){
    if( a == 'R' ) return 6;
    if( a == 'G') return 7;
    if( a=='B') return 8;
    if(a =='Y') return 9;
    return 10;
}
int getN(char c){
    return c - '0';
}
int get(int x){
    int ans = 0;
    while(x != 0){
        if(x % 2 == 1) ans++;
        x/=2;
    }
    return ans;
}
int a[11][11], b[11][11], c[11], cnt[11];
int dd1[11], dd2[11];
bool check(int x){
    for(int i = 1; i <= 10; i++){
        c[i] = 0;
    }
    int z = 1;
    while( x ){
        if( x % 2 == 1){
            c[z] = 1;
        }
        x/=2;
        z++;
    }
    
    int cntt = 0;
    for(int i = 1; i <= 10; i++){
        if( c[i]==0 ){
            for(int j = i; j <= 10; j++){
                if( a[i][j] && c[j] == 0) cntt++;
            }
        }
        if( c[i] ){
            int x = 0;
            for(int j = 1; j <= 10; j++){
                if( a[i][j] && c[j] == 0) x++;
            }
            if( x > 1) return 0;
        }
    }
    return cntt <=1;
}
int main () {
    #ifdef LOCAL
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string t;
        cin >> t;
        int x = getC(t[0]), y = getN(t[1]);
        a[x][y] ++;
        a[y][x] ++;
        cnt[x]++;
        cnt[y]++;
    }
    int ans = 10;
    for(int i = 1; i <= 5; i++){
        for(int j  = 6; j <= 10; j++){

            for(int t = 0; t < 1024; t++){
                if( check(t)) ans = min(ans, get(t));
            }
        }
    }
    cout << ans << endl;
    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}