#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <cstdlib>
#include <cmath>


using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)
const int N = 2000 + 10;
const int INF = 1e9;

//struct event {
    //int t, dx;   
    //event() { }
    //event(int t, int dx): t(t), dx(dx) { }
//};

char a[N][N];
//vector < event > b;
int ans[N];


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    int n, m, k;
    scanf("%d%d%d\n", &n, &m, &k);
    for (int i = 0; i < n; i++)
        scanf("%s", a[i]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'U' && i % 2 == 0) {
                //cerr << "i: " << i << endl;
                ans[j]++;
                //b.pb(event(i, 1));
                //b.pb(event(i + 1, -1));
            }
            if (a[i][j] == 'R' && i + j < m) {
                ans[i + j]++;
            }
            if (a[i][j] == 'L' && j - i >= 0)
                ans[j - i]++;
        }
    for (int i = 0; i < m; i++)
        printf("%d ", ans[i]);
    printf("\n");
    return 0;
}