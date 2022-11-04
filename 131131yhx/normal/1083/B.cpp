#include <cstdio>
#include <cstring>
#include <algorithm>
#define M 1000010

using namespace std;

typedef long long ll;

int n, k;

ll ans = 0;

char S[M], T[M];

ll F[M];

void Do(int x, int bs, int bt) {
    if(x == n) {F[1]++; return;}
    int s1 = bs & (S[x] == 'a'), t1 = bt & (T[x] == 'a'), s2 = bs & (S[x] == 'b'), t2 = bt & (T[x] == 'b');
    if(!s1 && !s2 && !t1 && !t2) {
        F[n - x + 1]++;
        return;
    }
    //'a'
    if(!(bt == 1 && T[x] == 'b'))
        Do(x + 1, bs & (S[x] == 'a'), bt & (T[x] == 'a'));
    //'b'
    if(!(bs == 1 && S[x] == 'a'))
        Do(x + 1, bs & (S[x] == 'b'), bt & (T[x] == 'b'));
}

int main() {
    scanf("%d%d", &n, &k);
    if(k == 1) {
        printf("%d\n", n);
        return 0;
    }
    k -= 2;
    scanf("%s%s", S + 1, T + 1);
    //Do(1, 1, 1);
    for(int i = 1; i <= n + 1; i++) if(S[i] != T[i] || i == n + 1) {
        for(int j = i + 1; j <= n; j++) {
            if(S[j] == 'a') F[n - j + 1]++;
            if(T[j] == 'b') F[n - j + 1]++;
        }
        ans = (n - i + 1) * 2 + i - 1;
        break;
    }
    for(int i = n; i >= 1; i--) {
        if(F[i] <= k) {
            ans += F[i];
            F[i - 1] += F[i] * 2;
            F[i] = 0;
        } else {
            ans += (ll) k * i;
            printf("%lld\n", ans);
            return 0;
        }
    }
    printf("%lld\n", ans);
    return 0;
}