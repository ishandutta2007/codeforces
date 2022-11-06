#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back

int x;
char ch;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d of %c", &x, &ch);
    if (ch == 'm') { //! month
        if (x == 31)
            printf("7");
        if (x == 30)
            printf("11");
        if (x <= 29)
            printf("12");
    } else { //! week
        if (x == 5 || x == 6)
            printf("%d", 53);
        else
            printf("%d", 52);
    }


    return 0;
}