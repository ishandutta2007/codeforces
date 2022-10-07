#include <iostream>
#include <cstdio>

using namespace std;
#define forn(i, n) for(i = 0; i < n; i++)
#define forab(i, a, b) for(i = a; i < b; i++)
#define forba(i, b, a) for(i = b; i > a; i--)

typedef long long ll;
typedef double db;
const int maxn = 61;
const int maxr = 1e5;
const int inf = 1e9;
int b[maxn][maxn][maxn];
int a[maxn][maxn][maxn];


int main(){
    int n, m, r, i, j, k, t, s, f;
    cin >> n >> m >> r;
    forn(i, m)
        forn(j, n)
            forn(k, n)
                scanf("%d", &b[i][j][k]);
    forn(t, m)
        forn(k, n)
            forn(i, n)
                forn(j, n)
                    b[t][i][j] = min(b[t][i][j], b[t][i][k] + b[t][k][j]);
    forn(t, n)
        forn(i, n)
            forn(j, n)
                a[t][i][j] = inf;

    forn(i, n)
        forn(j, n)
            forn(k, m)
                a[0][i][j] = min(a[0][i][j], b[k][i][j]);               
    
    forab(t, 1, n)
        forn(k, n)
            forn(i, n)
                forn(j, n)
                    a[t][i][j] = min(a[t][i][j], a[t - 1][i][k] + a[0][k][j]);
    forn(i, r){
        scanf("%d%d%d", &s, &f, &k);
        k = min(k, n - 1);
        printf("%d\n", a[k][s - 1][f - 1]);
    }
    
    return 0;

}