#include<bits/stdc++.h>

using namespace std;

int N, M, take[1003][512], lineFor[1003], x[1003];

bitset<512> comb[1003][512];
bitset<512> sys[1003];
const int spc = 510;
const bool DBG = 0;

void print(bitset<512> curr, int lim, string s)
{
    printf("(");
    for (int i=0; i<lim; i++)
        if (curr[i]) printf("1");
        else printf("0");
    printf ("=");
    if (curr[spc]) printf("1");
    else printf("0");
    printf(")%s", s.c_str());
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

int tests, testId = 0;
scanf ("%d", &tests);
while (tests --)
{
    //printf ("Case #%d: ", ++testId);
    scanf ("%d", &N);
    for (int j=0; j<M; j+=2)
        comb[0][j / 2].reset(), comb[0][j / 2][j / 2] = 1;
    for (int i=1; i<N; i++)
        for (int j=0; j<N; j++)
            if ((i + j) % 2 == 0)
            {
                if (i % 2 == 1 && j + 1 < N)
                {
                    if (i == 1) comb[i][j / 2] = comb[i - 1][j / 2] ^ comb[i - 1][j / 2 + 1];
                    else comb[i][j / 2] = comb[i - 1][j / 2] ^ comb[i - 1][j / 2 + 1] ^ comb[i - 2][j / 2];
                }
                else
                if (i % 2 == 1)
                {
                    if (i == 1) comb[i][j / 2] = comb[i - 1][j / 2];
                    else comb[i][j / 2] = comb[i - 1][j / 2] ^ comb[i - 2][j / 2];
                }

                if (i % 2 == 0 && j > 0)
                    comb[i][j / 2] = comb[i - 1][j / 2 - 1] ^ comb[i - 1][j / 2] ^ comb[i - 2][j / 2];
                else
                if (i % 2 == 0 && j == 0)
                    comb[i][j / 2] = comb[i - 1][j / 2] ^ comb[i - 2][j / 2];
                comb[i][j / 2][spc] = comb[i][j / 2][spc] ^ 1;
            }
    int lines = 0;
    for (int j=0; j<N; j+=2)
    {
        ///need to enforce the system for (N - 1, j)
        sys[++lines] = comb[N - 1][j / 2] ^ comb[N - 2][j / 2];
        if (j > 0) sys[lines] ^= comb[N - 1][j / 2 - 1];
        sys[lines][spc] = sys[lines][spc] ^ 1;
    }
    for (int i=0; i<M; i++)
        x[i / 2] = 0, lineFor[i / 2] = -1;
    if (DBG)
    {
        for (int i=0; i<N; i++, printf("\n"))
            for (int j=0; j<N; j++)
            {
                bitset<512> curr;
                if ((i + j) % 2 == 0) curr = comb[i][j / 2];
                else curr.reset();
                print(curr, N / 2, " ");
            }
        printf("system:\n");
        for (int i=1; i<=lines; i++)
            print(sys[i], N / 2, "\n");
    }
    for (int i=1; i<=lines; i++)
    {
        int j = 1;
        while (sys[i][j] == 0 && j <= spc)
            j ++;
        assert(j != spc);
        if (j > spc) continue;
        lineFor[j] = i;
        for (int k=1; k<=lines; k++)
            if (k != i && sys[k][j] == 1)
                sys[k] ^= sys[j];
    }
    for (int i=0; i<M; i++)
        if (lineFor[i / 2] != -1)
            x[i / 2] = sys[lineFor[i / 2]][spc];
    for (int j=0; j<M; j+=2)
        take[0][j / 2] = x[j / 2];
    for (int i=1; i<N; i++)
        for (int j=0; j<N; j++)
            if ((i + j) % 2 == 0)
            {
                if (i % 2 == 1 && j + 1 < N)
                {
                    if (i == 1) take[i][j / 2] = take[i - 1][j / 2] ^ take[i - 1][j / 2 + 1];
                    else take[i][j / 2] = take[i - 1][j / 2] ^ take[i - 1][j / 2 + 1] ^ take[i - 2][j / 2];
                }
                else
                if (i % 2 == 1)
                {
                    if (i == 1) take[i][j / 2] = take[i - 1][j / 2];
                    else take[i][j / 2] = take[i - 1][j / 2] ^ take[i - 2][j / 2];
                }

                if (i % 2 == 0 && j > 0)
                    take[i][j / 2] = take[i - 1][j / 2 - 1] ^ take[i - 1][j / 2] ^ take[i - 2][j / 2];
                else
                if (i % 2 == 0 && j == 0)
                    take[i][j / 2] = take[i - 1][j / 2] ^ take[i - 2][j / 2];
                take[i][j / 2] ^= 1;
            }
    int ans = 0;
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
        {
            int x;
            scanf ("%d", &x);
            if ((i + j) % 2 == 0)
            {
                if (take[i][j / 2]) ans ^= x;
            }
            else
            {
                if (take[N - 1 - i][j / 2]) ans ^= x;
            }
        }
    printf ("%d\n", ans);
}

return 0;
}

/*
const int seed = time (0);
mt19937 gen (seed);
long long getRand(long long a, long long b) {return uniform_int_distribution < long long > (a, b) (gen);}
*/