#include<bits/stdc++.h>

using namespace std;

const int maxN = 2021;
int N, K, c[maxN][maxN];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &K);
int lg = 0, p = 1;
while (p < N)
    lg ++, p *= K;
for (int i=0; i<N; i++) {
    for (int j=0; j<i; j++) {
        int ans = 0, currI = i, currJ = j;
        for (int k=0; k<lg; k++) {
            int x = currI % K, y = currJ % K;
            currI /= K, currJ /= K;
            if (y < x) {
                ans = k + 1;
                break;
            }
        }
        assert(ans != 0);
        c[j][i] = ans;
    }
}
printf("%d\n", lg);
for (int i=0; i<N; i++)
    for (int j=i + 1; j<N; j++)
        printf("%d ", c[i][j]);
printf("\n");

return 0;
}

/*
const int seed = time (0);
mt19937 gen (seed);
long long getRand(long long a, long long b) {return uniform_int_distribution < long long > (a, b) (gen);}
*/