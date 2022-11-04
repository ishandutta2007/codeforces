#include <cstdio>
#include <cstring>
#include <algorithm>
#define M 500010
#define int long long

using namespace std;

typedef long long ll;

int n, A[M], B[M], canA[M], canB[M], SA[M], SB[M];

char ch[M];

signed main() {
    scanf("%lld", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%s", ch + 1);
        int st = strlen(ch + 1);
        int t = 0;
        canA[i] = 1;
        canB[i] = 1;
        for(int j = 1; j <= st; j++) {
            if(ch[j] == '(') t++;
            else if(ch[j] == ')') t--;
            if(t < 0) {
                canA[i] = 0;
                break;
            }
        }
        A[i] = t;
        if(canA[i]) SA[A[i]]++;
        t = 0;
        reverse(ch + 1, ch + st + 1);
        for(int j = 1; j <= st; j++) ch[j] = (ll) '(' + ')' - ch[j];
        for(int j = 1; j <= st; j++) {
            if(ch[j] == '(') t++;
            else if(ch[j] == ')') t--;
            if(t < 0) {
                canB[i] = 0;
                break;
            }
        }
        B[i] = t;
        if(canB[i]) SB[B[i]]++;
    }
    ll ans = SA[0] / 2;
    for(int i = 1; i <= 500000; i++) ans += min(SA[i], SB[i]);
    printf("%lld\n", ans);
    return 0;
}