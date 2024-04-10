#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 100003;

int n, m, k;
int rn, mn, rm, mm, xn, xm;
char s[MAXN];

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif
    gets(s);
    int l = strlen(s);
    rn = rm = -1;
    for (int i = 0; i < l; i++)
    {
        if (s[i] == '0') n++, rn = mn = i; else
        if (s[i] == '1') m++, rm = mm = i; else
            k++, mn = mm = i;
    }

    for (int i = 0; i < rm; i++)
        xm += s[i] == '?' || s[i] == '0';
    for (int i = 0; i < rn; i++)
        xn += s[i] == '?' || s[i] == '1';

    int N = (l - 2 + 1) / 2, M = (l - 2) / 2;
    if (m <= N) puts("00");
    if (m + k > N && n + k > M)
    {
        if (rn < mm && n + k - 1 > M || rn < rm && xm > M) puts("01");
        if (rm < mn && m + k - 1 > N || rm < rn && xn > N) puts("10");
    }
    if (n <= M) puts("11");
    return 0;
}