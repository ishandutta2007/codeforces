#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long double LD;
#define N 500000 + 5

int len;
LD u, v, ans, H[N];
char s[N];

int main()
{
    scanf("%s", s + 1);
    len = strlen(s + 1);
    for (int i = 1; i <= len; i ++)
        H[i] = H[i - 1] + (LD) 1 / i;
    for (int i = 2; i <= len; i ++)
        H[i] += H[i - 1];
    for (int i = 1; i <= len; i ++)
    {
        if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'Y')
            ans += H[len] - H[i - 1] - H[len - i];
    }
       
    printf("%.7lf\n", (double) ans);
    
    return 0;
}