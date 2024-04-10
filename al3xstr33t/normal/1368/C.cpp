#include<bits/stdc++.h>

using namespace std;

int N;
set < pair < int, int > > S;

void add (int x, int y)
{
    S.insert ({x, y});
}

void print ()
{
    printf ("%d\n", S.size ());
    for (auto it : S)
        printf ("%d %d\n", it.first, it.second);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=0; i<2; i++)
    for (int j=0; j<2; j++)
        add (i, j);
for (int i=1; i<=N; i++)
    add (i + 1, i),
    add (i, i + 1),
    add (i + 1, i + 1);
print ();
return 0;
}