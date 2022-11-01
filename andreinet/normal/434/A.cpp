#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

const int Nmax = 100005;

int A[Nmax];
vector <int> G[Nmax];

int modul(int k) {return (k < 0 ? -k: k);}

int main()
{
    //freopen("input", "r", stdin);
    //freopen("output", "w", stdout);

    int N, M;
    scanf("%d%d%d", &N, &M, &A[1]);

    for (int i = 2; i <= M; i++)
    {
        scanf("%d", &A[i]);

        if (A[i] != A[i - 1])
        {
            G[A[i]].push_back(A[i - 1]);
            G[A[i - 1]].push_back(A[i]);
        }
    }

    long long s = 0;
    for (int i = 2; i <= M; i++)
        s += modul(A[i] - A[i - 1]);

    long long Stot = s;

    //printf("%I64d\n", s);

    for (int i = 1; i <= N; i++)
    {
        long long sum = 0;
        for (int j = 0; j < int(G[i].size()); j++)
            sum += modul(i - G[i][j]);

        sort(G[i].begin(), G[i].end());

        long long sum2 = 0;
        int med = G[i].size() / 2;

        for (int j = 0; j < int(G[i].size()); j++)
            sum2 += modul(G[i][med] - G[i][j]);

        s = min(s, Stot - sum + sum2);
    }

    printf("%I64d\n", s);
}