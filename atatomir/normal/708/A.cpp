#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 100011

int n, i;
char s[maxN];
bool all = true;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%s", s + 1);
    n = strlen(s + 1);

    for (i = 1; i <= n; i++)
        if (s[i] != 'a')
            all = false;

    if (all) {
        s[n] = 'z';
        printf("%s\n", s + 1);
        return 0;
    }

    for (i = 1; s[i] == 'a'; i++);
    for (; s[i] != 'a' && i <= n; i++) s[i]--;

    printf("%s\n", s + 1);

    return 0;
}