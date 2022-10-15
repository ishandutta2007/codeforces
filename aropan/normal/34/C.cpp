#include <cstdio>

using namespace std;

const int MAXN = 1111;

int a[MAXN];
bool flag;

int main()
{
/*
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
//*/
    int x;
    while (scanf("%d,", &x) != EOF)
        a[x]++;

    for (int i = 0, j = 0; i < MAXN; i = j)
    {
        while (i < MAXN && a[i] == 0) i++;
        if (i == MAXN) break;

        j = i;
        while (j < MAXN && a[j] != 0) j++;

        if (flag) printf(",");
        flag = true;

        if (i + 1 == j) 
            printf("%d", i);
        else
            printf("%d-%d", i, j - 1);
    }
    printf("\n");
    return 0;
}