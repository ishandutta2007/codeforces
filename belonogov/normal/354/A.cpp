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

#define epr(...) fprintf(stderr, __VA_ARGS__)

const int maxn = 1e5 + 2;
const int inf = 1e9;

int a[maxn];
int p[maxn];

int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
    int n, l, r, Ql, Qr, res, ans;
    scanf("%d%d%d%d%d\n", &n, &l, &r, &Ql, &Qr);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    p[0] = 0;
    for (int i = 0; i < n; i++)
        p[i + 1] = p[i] + a[i];
    ans = inf * 2 + 1;
    for (int i = 0; i <= n; i++){
        res = p[i] * l + (p[n] - p[i]) * r;
        if (i * 2 < n)
            res += (n - i * 2 - 1) * Qr;    
        else{
            if (i * 2 != n)             
                res += (n - (n - i) * 2 - 1) * Ql;
        }
        ans = min(ans, res);
    }
    cout << ans << endl;
 
 
    return 0;
}