#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 105;
const int MAXM = 1005;

char s[MAXN][MAXM];

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%s", s[i]);
    
    int sol = 0;
    for (int i = 0; i < 26; i++)
        for (int j = 0; j < 26; j++) {
            int sum = 0;
            for (int k = 0; k < N; k++) {
                bool ok = true;
                for (int l = 0; s[k][l]; l++)
                    if (s[k][l] != 'a' + i && s[k][l] != 'a' + j)
                        ok = false;
                if (ok) sum += strlen(s[k]);
            }
            sol = max(sol, sum);
        }
    
    printf("%d\n", sol);
    return 0;
}