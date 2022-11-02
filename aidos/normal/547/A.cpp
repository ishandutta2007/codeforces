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
const int maxn = (int) 2e6 + 10;

using namespace std;
int m, a11, h11, x11, y11, a22, h22, x22, y22;
int pr1, pr2;
int fi1, fi2;
int was[maxn];

void calc(int &pr, int &fi, int h, int a, int x, int y){
    fi = -1;
    pr = -1;
    for(int i = 0; i < 10 * m; i++){
        if(h==a) {
            if(fi == -1) fi = i;
            else {
                pr = i - fi;
                return;
            }
        }
        h = (x * 1ll * h % m + y) % m;
    }
}




int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> m >> h11 >> a11 >> x11 >> y11 >> h22 >> a22 >> x22 >> y22;
    calc(pr1, fi1, h11, a11, x11, y11);
    calc(pr2, fi2, h22, a22, x22, y22);
    if(fi1 == -1 || fi2 == -1){
        cout << -1 << endl;
        return 0;
    }
    if(fi1 == fi2){
        cout << fi1 << endl;
        return 0;
    }
    if(pr1 == -1 && pr2 == -1){
        cout << -1 << endl;
        return 0;
    }
    
    if(pr1 == -1){
        if(fi1 < fi2 || (fi1 - fi2) % pr2 != 0 ){
            cout << -1 << endl;
        }
        else cout << fi1 << endl;
        return 0;
    }
    if(pr2 == -1){
        if(fi1 > fi2 || (fi2 - fi1) % pr1 != 0 ){
            cout << -1 << endl;
        }
        else cout << fi2 << endl;
        return 0;
    }
    for(int i=0; i < 20000000; i++){
        ll ti1 = fi1 + pr1 * 1ll * i;
        if(ti1 >= fi2 && (ti1 - fi2) % pr2 == 0){
            cout << ti1 << endl;
            return 0;
        }
    }
    for(int i=0; i < 20000000; i++){
        ll ti1 = fi2 + pr2 * 1ll * i;
        if(ti1 >= fi1 && (ti1 - fi1) % pr1 == 0){
            cout << ti1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;






    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}