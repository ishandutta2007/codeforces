#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <queue>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
// #define "%lld" "%I64d"


#define epr(...) fprintf(stderr, __VA_ARGS__)

const int maxn = 1e5 + 2;
const long long inf = 3e10;


long long a[maxn];
long long b[maxn];
int n, m;

bool solve(long long t){
    long long t1;
    int cur = 0, res, res1, res2;
    for (int i = 0; cur < m && i < n; i++){
        if (b[cur] < a[i]){
            t1 = t - (a[i] - b[cur]);
            if (t1 < 0)
                return 0;
        
            for (res1 = cur + 1; res1 < m && b[res1] - b[cur] <= t1; res1++);
            
            for (res2 = cur; res2 < m && abs(a[i] - b[res2]) + b[res2] - b[cur] <= t; res2++);
            
            res = max(res2, res1);
            if (res == cur)
                return 0;
            cur = res;
        }
        else
            for (;cur < m && b[cur] - a[i] <= t; cur++);                
    }
    return cur == m;    
}


int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
//      scanf("%lld", &a[i]);
        scanf("%I64d", &a[i]);
        
    for (int i = 0; i < m; i++)
        scanf("%I64d", &b[i]);
    
    long long l = -1, r = inf;
    while (r - l > 1){
        if (solve((l + r) / 2))
            r = (l + r) / 2;
        else
            l = (l + r) / 2;        
    }
    cout << r << endl;
    
 
 
    return 0;
}