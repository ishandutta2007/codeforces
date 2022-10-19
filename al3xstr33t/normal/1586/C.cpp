#include<bits/stdc++.h>

using namespace std;

const int maxN = 1e6 + 100;
int N, M, s[maxN];
char currS[maxN];
string a[maxN];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d\n", &N, &M);
for (int i=0; i<N; i++) {
    scanf ("%s\n", currS);
    a[i] = currS;
}
for (int j=0; j<M; j++) {
    bool bad = 0;
    for (int i=1; i<N; i++) {
        if (a[i - 1][j] == 'X' && (j == 0 || a[i][j - 1] == 'X'))
            bad = 1;
    }
    int ok = 1 - bad;
    s[j] = (j == 0 ? ok : s[j - 1] + ok);
}
int Q;
scanf ("%d", &Q);
while (Q --) {
    int j1, j2;
    scanf ("%d %d", &j1, &j2), j1 --, j2 --;
    if (s[j2] - s[j1] == j2 - j1) printf ("YES\n");
    else printf("NO\n");
}
return 0;
}

/*
const int seed = time (0);
mt19937 gen (seed);
long long getRand(long long a, long long b) {return uniform_int_distribution < long long > (a, b) (gen);}
*/