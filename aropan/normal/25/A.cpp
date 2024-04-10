#include<cstdio>
using namespace std;

int a[2][3];

int n;


int main()
{
    /*
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    //*/
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int x, k;
        scanf("%d", &x);
        k = x & 1;
        if (a[k][0] < 2)
            a[k][++a[k][0]] = i;
    }
    printf("%d\n", a[a[1][0] == 1][1]);
    return 0;
}