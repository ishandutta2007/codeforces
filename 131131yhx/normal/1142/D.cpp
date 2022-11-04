#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

char ch[200010];

int n, F[200010][11];

int main() {
    scanf("%s", ch + 1), n = strlen(ch + 1);
    for(int j = 0; j < 11; j++) F[n + 1][j] = n, F[n][j] = n;
    long long ans = 0;
    for(int i = n - 1; i >= 1; i--) {
        for(int j = 0; j < 11; j++) {
            int t = j; // l = 0
            int nwrk = (t + 1) % 11;
            if(nwrk <= ch[i + 1] - '0') {
                F[i][j] = i;
                continue;
            }
            t = (10 + t * (t + 1) / 2 - 1 + (ch[i + 1] - '0')) % 11;
            nwrk = (t + 1) % 11;
            if(nwrk <= ch[i + 2] - '0' || i + 2 > n) {
                F[i][j] = i + 1;
                continue;
            }
            t = ((10 + t) * (t - 10 + 1) / 2 - 1 + (ch[i + 2] - '0') + 1100000) % 11;
            F[i][j] = F[i + 2][t];
        }
    }
    for(int i = 1; i <= n; i++) if(ch[i] != '0') ans += F[i][ch[i] - '0' - 1] - i + 1;
    printf("%lld\n", ans);
    return 0;
}