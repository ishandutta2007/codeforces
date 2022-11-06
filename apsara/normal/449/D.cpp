#include<stdio.h>
#include<cmath>
#include<stdlib.h>
#include<algorithm>
#include<iostream>
#include<cstring>
#define ll long long
using namespace std;

const int maxn = 1000010;
const int maxm = 20;
const ll mod = 1000000007;
int c[maxn];
int cnt(int x)
{
    int ret = 0;
    while (x > 0) {
        if (x&1) ret++;
        x /= 2;
    }
    return ret;
}
int a[maxn][maxm + 1], b[maxn];
ll cal(ll x, ll n)
{
    ll y = 1;
    while (n) {
        if (n&1) y = x * y % mod;
        n /= 2;
        x = x * x % mod;
    }
    return y;
}
int n;
int main()
{
   // cout<<(1<<20);
    scanf("%d",&n);
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    for (int i = 0; i < maxn; i++)
        c[i] = cnt(i);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d",&x);
        a[x][c[x]]++;
    }
    for (int i = maxn - 1; i >= 0; i--)
        for (int j = 0; j < maxm; j++)
        if (a[i][j]) {
            if (j > c[i]) {
                a[i][j] = a[i][j] / (j - c[i]);
            }
            for (int k = 0; k < maxm; k++)
            if (i & (1<<k)) {
                int ni = (i ^ (1<<k));
                a[ni][j] = (a[ni][j] + a[i][j]) % mod;
            }
            b[i] = (b[i] + a[i][j]) % mod;
            //cout<<i<<' '<<j<<' '<<b[i]<<endl;
        }
    ll ans = 0;
    //cout<<ans<<endl;
    for (int i = 0; i < maxn; i++)
    if (b[i]) {
        //cout<<i<<' '<<b[i]<<' '<<cal(2,b[i])<<endl;
        ll p;
        if (c[i]&1) p = -1;
        else p = 1;
        ans = (ans + (p * (cal(2,b[i]) - 1 + mod) % mod + mod)) % mod;
    }
    cout<<ans<<endl;
}