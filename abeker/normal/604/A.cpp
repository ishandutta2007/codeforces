#include <cstdio>
#include <algorithm>
using namespace std;

int m[5], w[5];

int main() {
    for (int i = 0; i < 5; i++)
        scanf("%d", m + i);
    for (int i = 0; i < 5; i++)
        scanf("%d", w + i);
    int hs, hu;
    scanf("%d%d", &hs, &hu);
    int score = 50 * (2 * hs - hu);
    for (int i = 0; i < 5; i++) 
        score += max(150 * (i + 1), 2 * (i + 1) * (250 - m[i]) - 50 * w[i]);
    printf("%d\n", score);
    return 0;
}