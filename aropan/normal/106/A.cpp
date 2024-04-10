#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;


const char *s = "6789TJQKA";

char m;
char d1, m1, d2, m2;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif

    scanf("%c\n%c%c %c%c", &m, &d1, &m1, &d2, &m2);
    puts((m1 != m2 && m1 == m || m1 == m2 && strchr(s, d2) < strchr(s, d1))? "YES" : "NO");
    return 0;
}