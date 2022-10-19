#include<bits/stdc++.h>

using namespace std;

const int maxN = 1e6;
int N, a[maxN];
bool cr[maxN + 10];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

for (int i=2; i * i<=maxN; i++)
    if (cr[i] == 0)
        for (int j=i * i; j<=maxN; j+=i)
            cr[j] = 1;

int tests, testId = 0;
scanf ("%d", &tests);
while (tests --) {
    int N, s = 0;
    scanf ("%d", &N);
    for (int i=1; i<=N; i++)
        scanf ("%d", &a[i]), s += a[i];
    vector<int> toDel;
    if (cr[s]) printf ("%d\n", N);
    else {
        bool ok = 0;
        for (int i=1; i<=N; i++) {
            ok |= cr[s - a[i]];
            if (ok) {
                toDel.push_back(i);
                break;
            }
        }
        if (ok) printf("%d\n", N - 1);
        else {
            for (int i=1; i<=N; i++)
                for (int j=i+1; j<=N; j++) {
                    ok |= cr[s - a[i] - a[j]];
                    if (ok) {
                        toDel.push_back(i);
                        toDel.push_back(j);
                        i = N + 1;
                        break;
                    }
                }
            if (ok) printf ("%d\n", N - 2);
            else printf("%d\n", N - 3);
        }
    }
    for (int i=1; i<=N; i++)
        a[i] = 0;
    for (auto i : toDel)
        a[i] = 1;
    for (int i=1; i<=N; i++)
        if (a[i] == 0)
            printf ("%d ", i);
    printf("\n");
}

return 0;
}

/*
const int seed = time (0);
mt19937 gen (seed);
long long getRand(long long a, long long b) {return uniform_int_distribution < long long > (a, b) (gen);}
*/