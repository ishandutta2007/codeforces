#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
char s[100001];
int s1[100001];
int s2[100001];


int a[100];
int b[100];

int main()
{
   int n, i, ans, uk, i2, kol, j, uk2;
    scanf("%s", s);
    n = strlen(s);
    for (i = 0; i < n; i++){
        a[s[i] - '0']++;
        b[s[i] - '0']++;
    }
    uk2 = n - 1;
    bool check = 1;
    for (i = 1; i <= 5; i++)
        if (a[i] && a[10 - i])
            check = 0;

    while (a[0] > a[9] || (check && a[0] > 0)){
        a[0]--;
        b[0]--;
        uk2--;
    }
    ans = -1;
    uk = -1;
    for (i = 1; i <= 5; i++){
        i2 = (10 - i) % 10;
        kol = 0;
        if (a[i] == 0 || a[i2] == 0)
            continue;
        b[i2]--;
        a[i]--;
        for (j = 0; j < 10; j++)
            kol += min(b[j], a[9 - j]);
        if (kol > ans){
            ans = kol;
            uk = i;
        }
        b[i2]++;
        a[i]++;
    }
    if (uk != -1){
        s1[uk2] = uk;
        s2[uk2--] = (10 - uk) % 10;
        a[uk]--;
        b[(10 - uk) % 10]--;
        for (i = 0; i < 10; i++)
            while (a[i] > 0 && b[9 - i] > 0){
                s1[uk2] = i;
                s2[uk2] = 9 - i;
                uk2 --;
                a[i]--;
                b[9 - i]--;
            }
        }
    uk = uk2;
    for (i = 0; i < 10; i++){
        while (a[i] > 0){
            s1[uk2--] = i;
            a[i]--;
        }
    }
    for (i = 0; i < 10; i++)
        while (b[i] > 0){
            s2[uk--] = i;
            b[i]--;
        }


    for (i = 0; i < n; i++)
        printf("%d", s1[i]);
    printf("\n");
    for (i = 0; i < n; i++)
        printf("%d", s2[i]);


    return 0;
}