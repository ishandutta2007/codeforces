#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int Nmax = 1000005;

char A[Nmax];
int Rem1[Nmax], Rem2[Nmax];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE

    fgets(A, Nmax, stdin);
    int N = strlen(A) - 1;

    if (A[0] == '0') {
        puts("NO");
        return 0;
    }

    int V1, V2;
    scanf("%d%d", &V1, &V2);

    for (int i = 1; i <= N; ++i) {
        int dig = A[i - 1] - '0';
        Rem1[i] = (Rem1[i - 1] * 10LL + dig) % V1;
    }
    for (int i = N, pow10 = 1; i > 0; --i) {
        int dig = A[i - 1] - '0';
        Rem2[i] = (Rem2[i + 1] + 1LL * dig * pow10) % V2;
        pow10 = 10LL * pow10 % V2;
    }

    for (int i = 1; i < N; ++i) {
        if (Rem1[i] == 0 && Rem2[i + 1] == 0 && A[i] != '0') {
            char c1 = A[i], c2 = A[i + 1];
            A[i] = '\n';
            A[i + 1] = '\0';
            printf("YES\n%s", A);
            A[i] = c1;
            A[i + 1] = c2;
            printf("%s", A + i);
            return 0;
        }
    }

    puts("NO");
}