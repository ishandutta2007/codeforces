#include<bits/stdc++.h>

using namespace std;

const int maxN = 1e6 + 100;
int N;
char s[maxN];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

int tests;
scanf ("%d", &tests);
while (tests --)
{
    scanf ("%d\n", &N);
    scanf ("%s", s + 1);
    for (int i=1; i<=N; i++)
        if (s[i] == 'b')
            printf ("%c", s[i]);
    for (int i=1; i<=N; i++)
        if (s[i] != 'b')
            printf ("%c", s[i]);
    printf ("\n");
}
return 0;
}