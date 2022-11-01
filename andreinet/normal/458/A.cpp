#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

const int Nmax = 100005;
const long double Eps = 1e-15;

char A[Nmax], B[Nmax];

int Na[4 * Nmax], Nb[4 * Nmax];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE

    fgets(A, Nmax, stdin);
    int N = strlen(A) - 1;
    reverse(A, A + N);

    fgets(B, Nmax, stdin);
    int M = strlen(B) - 1;
    reverse(B, B + M);

    for (int i = 0; i < N; i++)
        Na[i] = A[i] - '0';

    for (int i = 0; i < M; i++)
        Nb[i] = B[i] - '0';

    for (int i = 0; i <= 2 * N; i++) {
        if (Na[i] && Na[i + 1]) {
            Na[i]--;
            Na[i + 1]--;
            Na[i + 2]++;
        }

        if (Na[i] == 2) {
            Na[i - 2]++;
            Na[i + 1]++;
            Na[i] = 0;
            i -= 4;
        }
    }

    for (int i = 0; i <= 2 * M; i++) {
        if (Nb[i] && Nb[i + 1]) {
            Nb[i] --;
            Nb[i + 1]--;
            Nb[i + 2]++;
        }

        if (Nb[i] == 2) {
            Nb[i - 2]++;
            Nb[i + 1]++;
            Nb[i] = 0;
            i -= 4;
        }
    }

    for (int i = max(N, M) * 2; i >= 0; i--) {
        if (Na[i] < Nb[i]) {
            printf("<\n");
            return 0;
        }
        if (Na[i] > Nb[i]) {
            printf(">\n");
            return 0;
        }
    }

    printf("=\n");
}