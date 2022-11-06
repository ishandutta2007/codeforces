#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back

#define maxN 200011

int n, m, i;
char s[maxN];
char ch1, ch2;
int c1, c2;

int itIs[35];
int aux[35];

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d\n%s\n", &n, &m, s + 1);

    for (i = 0; i < 26; i++) itIs[i] = aux[i] = i;
    for (; m > 0; m--) {
        scanf("%c %c\n", &ch1, &ch2);
        c1 = ch1 - 'a';
        c2 = ch2 - 'a';

        c1 = aux[c1];
        c2 = aux[c2];
        swap(itIs[c1], itIs[c2]);
        swap(aux[ itIs[c1] ], aux[ itIs[c2] ]);
    }

    for (i = 1; i <= n; i++) printf("%c", 'a' + itIs[ s[i] - 'a' ]);

    return 0;
}