#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <cstring>
#include <cassert>
#include <ctime>


using namespace std;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#ifdef DEBUG
    #define epr(...) fprintf(stderr, __VA_ARGS__)
#else
    #define epr ()
#endif 


typedef long long ll;
typedef vector < int > vi;

const int maxn = -1;
const int inf = (int)1e9;



int main(){
//    freopen("in", "r", stdin);
//    freopen("out", "w", stdout);
    long long ans = 0, n, k, d, a;
    long long w;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> k >> a;
        if (a == 1)
            d = 1;
        else
            for(d = 0, w = 1; a > w; w *= 4, d++);
            
        ans = max(ans, k + d);
    }
    cout << ans << endl;

    return 0;
}