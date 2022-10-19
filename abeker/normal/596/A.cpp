#include <cstdio>
#include <algorithm>
using namespace std;

int N;
int x[5], y[5];

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d%d", x + i, y + i);
    
    int minx = *min_element(x, x + N);
    int maxx = *max_element(x, x + N);
    int miny = *min_element(y, y + N);
    int maxy = *max_element(y, y + N);
    
    if (minx == maxx || miny == maxy) puts("-1");
    else printf("%d\n", (maxx - minx) * (maxy - miny));
    
    return 0;
}