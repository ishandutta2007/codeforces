#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif

    int N, M;
    string S;
    cin >> S >> M;
    N = S.length();
    M += N;

    int Ans = 0;
    for (int size = 1; 2 * size <= M; size++)
    {
        for (int start = 0; start + 2 * size <= M; start++)
        {
            bool ok = 1;

            for (int i = start; i < start + size; i++)
                if (i < N && i + size < N && S[i] != S[i + size])
                    ok = 0;

            if (ok) Ans = size;
        }
    }

    cout << 2 * Ans << '\n';
}