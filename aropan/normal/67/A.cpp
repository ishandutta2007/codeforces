#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1001;

int l[MAXN], r[MAXN];
char s[MAXN];
int n;

int main()
{
/*
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
//*/
    scanf("%d\n", &n);
    for (int i = 1; i < n; i++)
        scanf("%c", &s[i]);


    l[0] = 1;
    for (int i = 1; i < n; i++)
        l[i] = l[i - 1] * (s[i] != 'L') + (s[i] != '=');


    r[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--)
        r[i] = r[i + 1] * (s[i + 1] != 'R') + (s[i + 1] != '=');


    for (int i = 0; i < n; i++)
    {
        if (i) printf(" ");
        printf("%d", max(l[i], r[i]));
    }
    return 0;
}