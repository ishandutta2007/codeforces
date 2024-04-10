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
const int maxn = 3e5;
const int inf = 1e9;

vector < pair < int, int > > basket[maxn];
int tmp[maxn];

int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    int n, cur, mxCur = 0, x, y, m, k, sumK = 0;
    scanf("%d", &n);
    for (int j = 0; j < n; j++) {
        scanf("%d%d%d%d%d", &k, &tmp[0], &x, &y, &m);
        sumK += k;
        for (int i = 1; i < k; i++) {
            tmp[i] = (tmp[i - 1] * 1ll *x + y) % m;
        } 
        cur = 0;
        for (int i = 0; i < k; i++) {
            if (i > 0 && tmp[i - 1] > tmp[i])
                cur++;
            if (sumK <= 200000)
                basket[cur].pb(mp(tmp[i], j));
        }
        mxCur = max(mxCur, cur);
    }
    printf("%d\n", mxCur);
    for (int i = 0; i <= mxCur; i++) {
        sort(basket[i].begin(), basket[i].end());
        for (int j = 0; j < (int)basket[i].size(); j++)
            if (sumK <= 200000)
                printf("%d %d\n", basket[i][j].fr, basket[i][j].sc + 1);
    } 
    

    return 0;
}