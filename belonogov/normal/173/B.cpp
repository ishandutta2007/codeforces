#include <iostream>
#include <cstdio>

using namespace std;
#define forn(i, n) for(i = 0; i < n; i++)
#define forab(i, a, b) for(i = a; i < b; i++)
#define forba(i, b, a) for(i = b; i > a; i--)

typedef long long ll;
typedef long double ld;
char a[1000][1000];
const int maxn = 1e3;

struct pnt{
    int x, y, c;
    pnt(){}
    pnt(int _x, int _y, int _c){
        x = _x;
        y = _y;
        c = _c;
    }
};

pnt och[maxn * 3];
bool usel[maxn];
bool useh[maxn];

int main(){
    int n, m, i, j;
    int uk1, uk2;
    pnt p;

    scanf("%d%d", &n, &m);
    forn(i, n)
        scanf("%s", a[i]);
    
    uk1 = 0;
    uk2 = 0;
    forn(j, m){
        if (a[n - 1][j] == '#')
            och[uk2++] = pnt(n - 1, j, 0);
    }
    for(; uk1 < uk2; uk1++){
        p = och[uk1];
        if (p.x == 0){
            printf("%d", p.c + 1);
            return 0;
        }
        usel[p.x] = true;
        useh[p.y] = true;
        forn(i, n)
            if (a[i][p.y] == '#' && !usel[i]){
                och[uk2++] = pnt(i, p.y, p.c + 1);
               usel[i] = true;
            }
        forn(j, m)
            if (a[p.x][j] == '#' && !useh[j]){
                och[uk2++] = pnt(p.x, j, p.c + 1);
               useh[j] = true;
            }
    }


    printf("-1");
    return 0;

}