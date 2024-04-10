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
const int maxn = 100;
const int inf = 1e9;

int a[maxn][maxn];

void add(int v, int u){
    a[v][u] = a[u][v] = 1;
}

int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
#endif
    int t, n, p;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d%d", &n, &p);
        memset(a, 0, sizeof(a));
        //cerr << "n p: " << n << " " << p << endl;
        for (int i = 0; i < n; i++)
            add(i, (i + 1) % n);
        if (n % 2 == 0) {
            for (int i = 0; i < n / 2; i++) {
                add(i * 2, (i * 2 + 2) % n);
                add(i * 2 + 1, (i * 2 + 2 + 1) % n);
            }
        }
        else {
            for (int i = 0, j = 0; j < n; j++, i = (i + 2) % n)
                add(i, (i + 2) % n);
        }
        //cerr << "asdfs\n";
        //cerr << "n: " << n << endl;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++)
                if (a[i][j] == 0 && p > 0) {
                    add(i, j);
                    p--;
                }
        }
        //cerr << "sdf\n";
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (a[i][j] == 1)
                    printf("%d %d\n", i + 1, j + 1); 
    }



    return 0;
}