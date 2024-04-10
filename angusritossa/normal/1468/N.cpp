#include <cstdio>
#include <algorithm>
using namespace std;

int t, c1, c2, c3, a1, a2, a3, a4, a5;

int main() {
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d%d%d", &c1, &c2, &c3);
        scanf("%d%d%d%d%d", &a1, &a2, &a3, &a4, &a5);
        int x;
        x = min(a1, c1); a1 -= x; c1 -= x;
        x = min(a2, c2); a2 -= x; c2 -= x;
        x = min(a3, c3); a3 -= x; c3 -= x;
        x = min(a4, c1); a4 -= x; c1 -= x;
        x = min(a5, c2); a5 -= x; c2 -= x;
        x = min(a4, c3); a4 -= x; c3 -= x;
        x = min(a5, c3); a5 -= x; c3 -= x;
        printf(a1==0&&a2==0&&a3==0&&a4==0&&a5==0 ? "YES\n" : "NO\n");
    }
}