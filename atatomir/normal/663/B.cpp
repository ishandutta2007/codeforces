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

#define maxS 111

int n, i, dim;
char s[maxS];

ll bg[15];
ll poww[15];

ll brute() {
    ll i;
    ll nr = 0;

    for (i = 0; i < dim; i++)
        nr += 1LL * poww[i] * (s[dim - i] - '0');

    for (i = bg[dim]; i < bg[dim + 1]; i++)
        if (nr == (i % poww[dim]) )
            return i;
}

ll smart() {
    int i;
    ll nr = 0;

    for (i = 0; i < dim; i++)
        nr += 1LL * poww[i] * (s[dim - i] - '0');



    if (nr < bg[dim])
        return poww[dim] + nr;
    else
        return nr;
}

ll get_year() {
    int i;

    dim = strlen(s + 1); dim -= 4;
    for (i = 1; i <= dim; i++)
        s[i] = s[i + 4];

    if (dim <= 3)
        return brute();
    else
        return smart();
}

int main()
{
    //freopen("test.in","r",stdin);

    bg[1] = 1989; poww[0] = 1; poww[1] = 10;
    for (i = 2; i <= 14; i++)
        bg[i] = bg[i - 1] + 1LL * poww[i - 1], poww[i] = poww[i - 1] * 10LL;

    scanf("%d\n", &n);
    for (i = 1; i <= n; i++) {
        memset(s, 0, sizeof(s));
        scanf("%s\n", s + 1);
        printf("%lld\n", get_year());
    }


    return 0;
}