#include <iostream>
#include <string>
#include <math.h>
#include <map>
#include <algorithm>
#include <vector>
#define Loop int loop = 0; loop < t; ++loop
#define LoopN int i = 0; i < n; ++i
#define LoopM int j = 0; j < m; ++j
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
using namespace std;

int main()
{
    const int P[] = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47 };
    int p = 0;
    for (int i : P)
    {
        printf("%i\n", i);
        fflush(stdout);
        char s[6];
        scanf("%s", s);
        if (s[0] == 'y')
        {
            ++p;
            if (p >= 2)
                break;
            if (i * i <= 100)
            {
                printf("%i\n", i * i);
                fflush(stdout);
                char s2[6];
                scanf("%s", s2);
                if (s2[0] == 'y')
                {
                    ++p;
                    if (p >= 2)
                        break;
                }
            }
        }
    }
    if (p < 2)
        printf("prime\n");
    else
        printf("composite\n");
    fflush(stdout);
}