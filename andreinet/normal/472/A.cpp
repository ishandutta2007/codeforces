#include <algorithm>
#include <bitset>
#include <cstdio>

using namespace std;

const int Nmax = 1000005;

bool notPrime[Nmax];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE

    int N;
    scanf("%d", &N);

    for (int i = 2; i * i < Nmax; ++i) {
        if (!notPrime[i]) {
            for (int j = i * i; j < Nmax; j += i)
                notPrime[j] = 1;
        }
    }

    for (int i = 2; i <= N; ++i) {
        if (notPrime[i] && notPrime[N - i]) {
            printf("%d %d\n", i, N - i);
            return 0;
        }
    }


}