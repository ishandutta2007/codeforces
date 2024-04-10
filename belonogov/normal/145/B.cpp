#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n, i, a1, a2, a3, a4, x, y, z;
    scanf("%d%d%d%d", &a1, &a2, &a3, &a4);
    if (a1 < a3 || a1 < a4 || a2 < a3 || a2 < a4){
        cout << -1;
        return 0;
    }
    n = a1 + a2;
    if (a3 - a4 > 1 || a3 - a4 < -1){
        cout << -1;
        return 0;
    }
    if (a3 > a4){
        x = a1 - a3;
        y = a2 - a3;
        if (x < 0 || y < 0){
            cout << -1;
            return 0;
        }
        for (i = 0; i < x; i++)
            printf("4");
        for (i = 0; i < a3; i++)
            printf("47");
        for (i = 0; i < y; i++)
            printf("7");
    }
    if (a3 == a4){
        x = a1 - a3 - 1;
        z = a2 - a3 - 1;
        y = a2 - a3;
        if ((x < 0 && z < 0)|| y < 0){
            cout << -1;
            return 0;
        }
        if (x < 0){
            printf("7");
            for (i = 0; i < a3; i++)
                printf("47");
            for (i = 0; i < z; i++)
                printf("7");
            return 0;
        }
        for (i = 0; i < x; i++)
            printf("4");
        for (i = 0; i < a3; i++)
            printf("47");
        for (i = 0; i < y; i++)
            printf("7");
        printf("4");
    }
    if (a3 < a4){
        x = a1 - a4;
        y = a2 - a4;
        if (x < 0){
            cout << -1;
            return 0;
        }
        printf("74");
        for (i = 0; i < x; i++)
            printf("4");
        for (i = 0; i < a4 - 2; i++)
            printf("74");
        for (i = 0; i < y; i++)
            printf("7");
        printf("74");
    }

    return 0;
}