#include <bits/stdc++.h>
using namespace std;


#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define pll pair < ll, ll >
#define all(s) s.begin(), s.end()
#define sz(s) (int) s.size()
#define vi vector < int >

const int inf = (1ll << 31) - 1;
const int mod = (int) 1e9 + 7;

int n, t;
string x, y;
char c[100100];
bool used[100100];

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> n >> t >> x >> y;
    t = n - t;
    for(int i = 0; i < n; i++){
        if( x[i] == y[i] && t > 0 ){
            c[i] = x[i];
            used[i] = 1;
            t--;
        }
    }
    int t1 = t;
    int t2 = t;
    for(int i = 0; i < n ; i++){
        if( t1 == 0 && t2 == 0) continue;
        if( x[i] == y[i]) continue;
        used[i] = 1;
        if(t1 > t2 ) {
            c[i] = x[i];
            t1--;
        } 
        else {
            c[i] = y[i];
            t2--;
        }
    }
    if( t1 || t2 ){
        cout << -1 << endl;
        return 0;
    }
    char cur[] = {'a', 'b', 'c'};
    for(int i = 0; i <n ;i++){
        if(!used[i]){
            for(int j = 0; j < 3; j++)
                if( cur[j] == x[i] || cur[j] == y[i]){
                
                }
                else c[i] = cur[j];
        }
        cout << c[i];
    }
    cout << endl;
    




    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}