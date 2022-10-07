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
const int maxn = 2000 + 10;
const int inf = 1e9;


int a[maxn][maxn];
//int b[maxn];
bool use[maxn];
queue < int > q;

int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
#endif
    int n, pos = -1, x, v;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            scanf("%d", &x);
            a[i][j] = x > 0;
            if (i == j && x > 0)
                pos = i; 
        }
    assert(pos != -1);
    bool flag = 1;
    for (int tt = 0; tt < 2; tt++) {
        //memset(b, 0, sizeof(b));
        memset(use, 0, sizeof(use));
        //for (int i = 0; i < n; i++)     
            //b[i] = a[pos][i];
        q.push(pos);
        use[pos] = 1;
        while (!q.empty()) {
            v = q.front();
            q.pop();
            for (int i = 0; i < n; i++)
                if (a[v][i] == 1 && !use[i]) {
                    use[i] = 1;
                    q.push(i);
                }
        }
        for (int i = 0; i < n; i++)
            if (use[i] == 0)
                flag = 0;


        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                swap(a[i][j], a[j][i]);
    }
    if (flag)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}