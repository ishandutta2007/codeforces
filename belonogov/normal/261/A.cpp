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

const int maxn = (int)2e5;
const int inf = (int)1e9;

int a[maxn];


bool cmp(int a, int b){
    return a > b;
}

int main(){
//     freopen("in", "r", stdin);
// //     freopen("out", "w", stdout);
    int minq = inf, m, n, ans, q;
    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        scanf("%d", &q);
        minq = min(q, minq);
    }
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n, cmp);
    minq += 2;
    ans = 0;
    for(int i = 0; i < n; i++){
        if (!(i % minq == minq - 1 || i % minq == minq - 2))
            ans += a[i];
    }
    printf("%d\n", ans);

    return 0;
}