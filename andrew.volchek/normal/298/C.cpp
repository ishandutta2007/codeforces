#include <cstring>
#include <cstdio>

char s[1111];

int main()
{
    gets(s);
    int len = strlen(s);
    int cnt1 = 0;
    for (int i = 0; i < len; i++)
        if (s[i] == '1')
            cnt1++;
    gets(s);
    len = strlen(s);
    int cnt2 = 0;
    for (int i = 0; i < len; i++)
        if (s[i] == '1')
            cnt2++;
    if (cnt1 & 1) cnt1++;
    if (cnt1 >= cnt2) printf("YES");
    else printf("NO");
    return 0;
}