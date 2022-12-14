#include <bits/stdc++.h>
#define gibon ios::sync_with_stdio(false); cin.tie(0);
#define fir first
#define sec second
#define pii pair<int, int>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
typedef long long ll;
using namespace std;
int dx[4]={0, 1, 0, -1}, dy[4]={1, 0, -1 , 0};
const int mxN=301000;
const int mxM=2100000;
const ll MOD=1000000007;
const int INF=100000000;
char s[mxN];
int gcd(int a, int b)
{
    if(a>b) return gcd(b, a);
    if(b%a==0)  return a;
    return gcd(b%a, a);
}
int main()
{
    gibon
    int t;
    cin >> t;
    while(t--)
    {
        ll m, d, w;
        cin >> m >> d >> w;
        if(m==1 || d==1)
        {
            cout << 0 << '\n';
            continue;
        }
        ll lim=min(m, d);
        ll div=w/gcd(w, d-1);
        ll namuji = lim%div;
        ll ans = namuji*(lim/div+1)*(lim/div)/2+(div-namuji)*(lim/div)*(lim/div-1)/2;
        cout << ans << '\n';
    }
}