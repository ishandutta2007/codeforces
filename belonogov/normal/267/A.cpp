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
#define forn(i, n) for(int i = 0; i < n; i++)
#define forab(i, a, b) for(int i = a; i < b; i++)
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

const int maxn = 2e5;
const int inf = 1e9;


int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
    int n, a, b, ans, k;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &a, &b);
        ans = 0;
        for(; a != 0 && b != 0;){
            if (a > b) swap(a, b);
            k = b / a;
            b -= k * a;
            ans += k;
        }
        printf("%d\n", ans);
    }

    return 0;
}