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

const int maxn = 1000;
const int inf = 1e9;

int a[maxn * 2][maxn * 2];
queue < pair < int, int > > q;

inline void check(int x, int y){
    if (a[x + maxn][y + maxn] >= 4) q.push(mp(x, y));
}

int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
    int n, t;
    int x, y;
    scanf("%d%d", &n, &t);
    a[maxn][maxn] = n;
    q.push(mp(0, 0));
    for(;!q.empty();){
    x = q.front().fr;
    y = q.front().sc;
    q.pop();
    if (a[x + maxn][y + maxn] < 4) continue;
    
    a[x + maxn][y + maxn] -= 4;
    a[x + 1 + maxn][y + maxn]++;
    a[x - 1 + maxn][y + maxn]++;
    a[x + maxn][y + 1 + maxn]++;
    a[x + maxn][y - 1 + maxn]++;
    check(x, y);
    check(x - 1, y);
    check(x + 1, y);
    check(x, y + 1);
    check(x, y - 1);    
    }
    for(int i = 0; i < t; i++){
    scanf("%d%d", &x, &y);
    if (abs(x) > maxn - 10 || abs(y) > maxn - 10){
        printf("0\n");
        continue;
    }
    assert(a[x + maxn][y + maxn] >= 0 && a[x + maxn][y + maxn] < 4); 
    printf("%d\n", a[x + maxn][y + maxn]);
    }
    return 0;
}