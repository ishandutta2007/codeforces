#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXL = 100007;

char s[MAXL];
char c[MAXL];
int a[26], b[26];
int n, m;
int ans;


int check()
{
    for (int j = 0; j < 26; j++)
        if (a[j] > b[j])
            return 0;
    ans++;
    return 1;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif

    gets(s);
    gets(c);

    n = strlen(s);
    m = strlen(c);

    if (n < m)
    {
        puts("0");
        return 0;
    }



    for (int i = 0; i < m; i++)
    {
        if (s[i] != '?') a[s[i] - 'a']++;
        b[c[i] - 'a']++;
    }

    ans = 0;
    for (int i = m; i < n; i++)
    {
        check();

        if (s[i] != '?') a[s[i] - 'a']++;
        if (s[i - m] != '?') a[s[i - m] - 'a']--;
    }
    check();
    printf("%d\n", ans);
    return 0;
}