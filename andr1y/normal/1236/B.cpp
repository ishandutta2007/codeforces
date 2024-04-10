#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#pragma GCC optimize("unroll-loops")
#include <stdio.h>
#define ll long long
#define M 1000000007
using namespace std;
ll binpowmod(ll a, ll b){
    if(b == 0) return 1;
    if(b == 1) return a%M;
    ll prev = binpowmod((a*a)%M, b/2);
    if(b%2 == 0) return prev%M;
    else return (prev*a)%M;
}
main(){
    ll n, m;
    scanf("%lld %lld", &n, &m);
    printf("%lld", binpowmod(binpowmod(2, m)-1, n));
}