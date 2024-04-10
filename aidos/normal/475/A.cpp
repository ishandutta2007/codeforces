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

#define MAXN (int) (1e7)
using namespace std;

vector < int > v[35];
void ff(int x){
    if( x ) cout << "O";
    else cout << "#";
}

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    int n;
    cin >> n;
    for(int i = 0; i < 4; i++) v[0].pb(0);
    for(int j = 1; j < 11; j++){
        for(int i=0; i < 3; i++) v[j].pb( 0 );
    }
    for(int i = 0; i < n; i++){
        int ok = 1;
        for(int k = 0; k < 15 && ok; k++){
         for(int j = 0; j < v[k].size() && ok; j++){
            if( v[k][j] == 0){
                v[k][j] = 1;
                ok = 0;
            }
         }
        }
    }
    cout << "+------------------------+" << endl;

    for(int i = 0; i < 4; i++){
        cout << "|";
        for(int j = 0; j < 11; j++){
        if( i==2 && v[j].size() == 3){
            cout << "..";
        }
        else if( i == 2 && v[j].size() == 4){
            ff( v[j][i]);
            cout <<".";
        }
        else if( i == 3 && v[j].size()==3){
            ff( v[j][i-1]);
            cout<<".";
        }
        else {
            ff(v[j][i]);
            cout <<".";
        }
        }
        if( i == 0 ) cout << "|D|)\n";
        else if( i==3) cout << "|.|)\n";
        else if( i == 1) cout << "|.|\n";
        else cout << "..|\n";
    }

    cout << "+------------------------+";

    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}