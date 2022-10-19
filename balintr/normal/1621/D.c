#include <stdio.h>
#pragma GCC optimize "Ofast"
#pragma GCC target "avx,avx2"

typedef long long ll;
#define min(a, b) ((a)<(b)?(a):(b))
#define MDIGITS 16
ll PW10[MDIGITS] = {0, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, (ll)1e10, (ll)1e11, (ll)1e12, (ll)1e13, (ll)1e14, (ll)1e15};
#define IO_SZ (3 << 20)
char _buf[IO_SZ], *_ii = _buf, *_oi = _buf;
#define scan(x){for(x=*_ii++-'0'; *_ii++>='0'; x=x*10+_ii[-1]-'0');}
void print(ll x){int digits=0; for(; digits<MDIGITS && PW10[digits]<=x; ++digits); for(char *i=_oi+digits-1; i>=_oi; --i, x/=10) *i=x%10+'0'; _oi+=digits;}

#define MN 500
int t, n;
int arr[MN][MN];

int main(){
    fread(_buf, 1, IO_SZ, stdin);
    scan(t);
    while(t--){
        scan(n);
        for(int i = 0; i < 2*n; i++) for(int j = 0; j < 2*n; j++) scan(arr[i][j]);
        ll ans = 0x3f3f3f3f;
        ans = min(ans, arr[0][n]);
        ans = min(ans, arr[0][2*n-1]);
        ans = min(ans, arr[n-1][n]);
        ans = min(ans, arr[n-1][2*n-1]);
        ans = min(ans, arr[n][0]);
        ans = min(ans, arr[n][n-1]);
        ans = min(ans, arr[2*n-1][0]);
        ans = min(ans, arr[2*n-1][n-1]);
        for(int i = n; i < 2*n; i++) for(int j = n; j < 2*n; j++) ans += arr[i][j];
        print(ans); *_oi++ = '\n';
    }
    fwrite(_buf, 1, _oi-_buf, stdout);
}