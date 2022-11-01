#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int Nmax = 100005, MOD = 1000000007;

int Fact[Nmax], InvFact[Nmax];
vector <int> divs;

int invmod(const int);

void Init()
{
    Fact[0] = 1;
    for (int i = 1; i < Nmax; i++)
        Fact[i] = 1LL * Fact[i - 1] * i % MOD;

    for (int i = 0; i < Nmax; i++)
        InvFact[i] = invmod(Fact[i]);
}

int Pw(int x, int y)
{
    int ret = 1;

    for (; y; y >>= 1)
    {
        if (y & 1) ret = 1LL * ret * x % MOD;
        x = 1LL * x * x % MOD;
    }

    return ret;
}

int invmod(const int N)
{
    return Pw(N, MOD - 2);
}

int comb(const int N, const int K)
{
    if (K > N) return 0;
    return (1LL * Fact[N] * InvFact[K] % MOD) * InvFact[N - K] % MOD;
}

void Desc(int N)
{
    divs.clear();

    for (int i = 2; i * i <= N; i++)
    {
        if (N % i == 0)
        {
            divs.push_back(i);
            while (N % i == 0)
                N /= i;
        }
    }

    if (N > 1)
        divs.push_back(N);
}

int Sol;

void Back(const int N, const int K, const int k, const int nr, const int M)
{
    if (k == int(divs.size()))
    {
        const int add = comb(N / M - 1, K - 1);

        if (nr % 2 == 0)
            Sol = (Sol + add) % MOD;
        else
            Sol = (Sol - add + MOD) % MOD;

        return;
    }

    Back(N, K, k + 1, nr + 1, M * divs[k]);
    Back(N, K, k + 1, nr, M);
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input", "r", stdin);
        freopen("output", "w", stdout);
    #endif

    Init();

    int Q;
    scanf("%d", &Q);

    while (Q--)
    {
        int N, K;
        scanf("%d%d", &N, &K);

        Sol = 0;

        Desc(N);

        Back(N, K, 0, 0, 1);

        printf("%d\n", Sol);
    }

}