#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int Nmax = 3005;

int A[Nmax], B[Nmax], V[Nmax];

vector< pair<int, int> > Swaps;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input", "r", stdin);
        freopen("output", "w", stdout);
    #endif

    ios :: sync_with_stdio(false);

    int N, M;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> A[i];

    cin >> M;

    int K = 0, Cnt = 0;
    for (int i = 1; i <= N; i++)
    {
        if (B[i]) continue;

        K++;
        for (int j = A[i]; j != i; j = A[j])
            B[j] = K, Cnt++;

        B[i] = K;
    }

    V[1] = 1;
    if (Cnt < M)
    {
        for (int k = 1; k <= M - Cnt; k++)
        {
            int p;
            for (int i = 1; i <= N; i++)
            {
                if (!V[B[i]])
                {
                    p = i;
                    break;
                }
            }

            V[B[p]] = 1;
            Swaps.push_back(make_pair(1, p));
        }
    }
    else
    {
        for (int k = 1; k <= Cnt - M; k++)
        {
            int p, l;
            for (int i = 1; i <= N; i++)
            {
                if (i != A[i])
                {
                    p = i;
                    break;
                }
            }

            for (l = p + 1; l <= N; l++)
            {
                if (B[l] == B[p])
                   break;
            }

            Swaps.push_back(make_pair(p, l));
            swap(A[p], A[l]);

            memset(B, 0, sizeof(B)); K = 0;
            for (int i = 1; i <= N; i++)
            {
                if (B[i]) continue;

                K++;
                for (int j = A[i]; j != i; j = A[j])
                    B[j] = K;

                B[i] = K;
            }
        }
    }

    cout << Swaps.size() << "\n";

    for (auto p: Swaps)
        cout << p.first << " " << p.second << " ";

    cout << "\n";
}