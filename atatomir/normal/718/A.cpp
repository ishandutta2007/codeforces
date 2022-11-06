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

#define maxN 200011

int n, t, i, pos;
char s[maxN];

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d\n%s", &n, &t, s + 1);

    int last = n + 1;
    for (pos = n; s[pos] != '.'; pos--)
        if (s[pos] >= '5')
            last = pos;

    if (last == n + 1) {
        printf("%s", s + 1);
        return 0;
    }

    for (pos = last; s[pos] >= '4' && t-- > 0; pos--);
    if (s[pos] == '.') {
        s[pos] = '\0';

        s[0] = '0';
        s[pos - 1]++;
        for (i = pos - 1; i > 0; i--) {
            if (s[i] > '9') {
                s[i - 1]++;
                s[i] -= 10;
            }
        }

        if (s[0] != '0')
            printf("%s", s);
        else
            printf("%s", s + 1);
    } else {
        s[pos]++;
        s[pos + 1] = '\0';
        printf("%s",s + 1);
    }


    return 0;
}