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

struct edge{
    long long v[4];   
} v[10];
inline ll sqr(ll a){
    return a * a;
}
inline void go(int pos){
    if(pos >= 8){ 
        set < ll > vv;
        for(int i = 0; i < 8; i++){
            for(int j = i+1; j < 8; j++){
                    ll ans = 0;
                    for(int k = 0; k < 3; k++){
                        ans += sqr(v[i].v[k] - v[j].v[k]);
                    }
                    vv.insert(ans);
                    if( vv.size() > 3) return;
            }
        }
        if( vv.size() != 3)return;

        cout << "YES\n";
        for(int i =0;  i < 8; i++){
            for(int j=0;j<3; j++){
                cout << v[i].v[j]<<" ";
            }
            cout << endl;
        }
        exit(0);
    }   
        
        do{
            go(pos+1);
        }
        while(next_permutation(v[pos].v, v[pos].v+3));
}

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif

    for(int i=0; i < 8; i++){
        
        for(int j=0; j < 3; j++){
            cin >> v[i].v[j];
        }
        sort(v[i].v, v[i].v+3);
    }
    go(1);
    cout << "NO\n";

    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}