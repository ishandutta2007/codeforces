#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 105;
const int MOD = 1000000007;

char s[MAXN];
int pow[2 * MAXN];

int main() {
    scanf("%s", s);
    int N = strlen(s);
    pow[0] = 1;
    for (int i = 1; i < 2 * N; i++)
        pow[i] = pow[i - 1] * 2 % MOD;
        
    int sol = 0;
    for (int i = 0; i < N; i++)
        if (s[i] == '1') {
            sol += pow[2 * (N - 1) - i];
            if (sol >= MOD) sol -= MOD;
        }
        
    printf("%d\n", sol);
    return 0;
}