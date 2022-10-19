#include<bits/stdc++.h>

using namespace std;

const int maxN = 1e6;
int N, M, ap[maxN];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

int tests, testId = 0;
scanf ("%d", &tests);
while (tests --) {
    scanf ("%d %d", &N, &M);
    for (int i=1; i<=N; i++)
        ap[i] = 0;
    while (M --) {
        int a, b, c;
        scanf ("%d %d %d", &a, &b, &c);
        ap[b] = 1;
    }
    int root = 1;
    while (ap[root])
        root ++;
    for (int i=1; i<=N; i++)
        if (i != root)
            printf ("%d %d\n", i, root);
}

return 0;
}

/*
const int seed = time (0);
mt19937 gen (seed);
long long getRand(long long a, long long b) {return uniform_int_distribution < long long > (a, b) (gen);}
*/