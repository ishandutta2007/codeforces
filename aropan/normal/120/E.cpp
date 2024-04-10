#include <cstdio>
#include <cmath>
#include <algorithm>
#include <ctime>

using namespace std;

int n;
int m;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &m);
    while (m--)
    {
        scanf("%d", &n);
        printf("%d\n", (n & 1) ^ 1);
    }

    fprintf(stderr, "Time of execution: %.3lf sec.\n", (double)clock()/CLOCKS_PER_SEC);
    return 0;
}