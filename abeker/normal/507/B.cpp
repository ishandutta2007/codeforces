#include <cstdio>
#include <cmath>
using namespace std;

int main() {
    double r, x1, y1, x2, y2;
    scanf("%lf%lf%lf%lf%lf", &r, &x1, &y1, &x2, &y2);
    printf("%d\n", (int)ceil(sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) / (2 * r)));
    return 0;
}