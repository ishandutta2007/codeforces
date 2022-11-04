#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    if(n % 2 == 1) printf("0\n"); else
    printf("%d\n", (n / 2 - 1) / 2);
    return 0;
}