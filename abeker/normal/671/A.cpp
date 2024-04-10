#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

typedef long double ld;
typedef pair <ld, int> pii;

const int MAXN = 100005;

int N;
int ax, ay, bx, by, tx, ty;
int x[MAXN], y[MAXN];
vector <pii> adil, bera;

ld dist(int x1, int y1, int x2, int y2) {
    return sqrt((ld)(x1 - x2) * (x1 - x2) + (ld)(y1 - y2) * (y1 - y2));
}

int main() {
    scanf("%d%d%d%d%d%d", &ax, &ay, &bx, &by, &tx, &ty);
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d%d", x + i, y + i);
    
    ld tot = 0;
    for (int i = 0; i < N; i++) {
        ld tmp = dist(x[i], y[i], tx, ty);
        adil.push_back(pii(dist(ax, ay, x[i], y[i]) - tmp, i));
        bera.push_back(pii(dist(bx, by, x[i], y[i]) - tmp, i));
        tot += 2 * tmp;
    }    
       
    sort(adil.begin(), adil.end());
    sort(bera.begin(), bera.end());
    
    ld sol = 1e18;
    for (int i = 0; i < N && i < 2; i++)
        for (int j = 0; j < N && j < 2; j++)
            if (adil[i].second != bera[j].second) 
                sol = min(sol, adil[i].first + bera[j].first);          
    
    sol = min(sol, adil[0].first);
    sol = min(sol, bera[0].first);
    
    printf("%.15lf\n", (double)(sol + tot));
    
    return 0;
}