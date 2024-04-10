#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int Nmax = 100005;

int Count[Nmax];
int Sum[2][Nmax];

char A[Nmax];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE

    fgets(A + 1, Nmax, stdin);
    const int N = strlen(A + 1) - 1;

    long long Sol1 = 0, Sol2 = 0;

    int S1 = 0, S2 = 0;

    for (int i = 1; i <= N; i++)
    {
        swap(S1, S2);
        if (A[i] == 'a')
        {
            S1++;
            Sol1 += S1;
            Sol2 += S2;
        }
    }

    S1 = 0, S2 = 0;

    for (int i = 1; i <= N; i++)
    {
        swap(S1, S2);
        if (A[i] == 'b')
        {
            S1++;
            Sol1 += S1;
            Sol2 += S2;
        }
    }

    #ifndef ONLINE_JUDGE
    //printf("%lld %lld\n", Sol2, Sol1);
    #endif

    printf("%I64d %I64d\n", Sol2, Sol1);

    return 0;
}