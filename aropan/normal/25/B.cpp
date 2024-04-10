#include<cstdio>
using namespace std;


int n;

int main()
{
    /*
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    //*/
    scanf("%d\n", &n);
    for (int i = 1; i <= n; i++)
    {
        char c;
        scanf("%c", &c);
        printf("%c", c);
        if (i % 2 == 0 && i + 2 <= n) printf("-");
    }
    printf("\n");
    return 0;
}