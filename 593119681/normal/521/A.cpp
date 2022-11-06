#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 1000000 + 5
#define Mod 1000000007

int n, ans, Max, cnt, Cnt[26];
char s[N];

inline int power(int u, int v)
{
    int res = 1;
    for (; v; v >>= 1)
    {
        if (v & 1) res = (LL) res * u % Mod;
        u = (LL) u * u % Mod;
    }
    return res;
}

int main()
{
    scanf("%d", &n);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i ++)
        Cnt[s[i] - 'A'] ++;
    for (int i = 0; i < 26; i ++)
        if (Cnt[i] > Max)
            Max = Cnt[i], cnt = 1;
        else if (Cnt[i] == Max) cnt ++;
    printf("%d\n", power(cnt, n));
    
    return 0;
}