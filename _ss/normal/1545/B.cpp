#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(), vr.end()
#define vi vector<int>
#define vll vector<ll>
const int N = 2e5 + 10;
const ll mod = 998244353;
int n;
char a[N];
ll ifact[N],fact[N],inv[N];

void build(int h)
{
    inv[1]=ifact[0]=ifact[1]=fact[0]=fact[1]=1;
    for (int i=2;i<=h;i++)
    {
        inv[i]=mod-mod/i*inv[mod%i]%mod;
        ifact[i]=ifact[i-1]*inv[i]%mod;
        fact[i]=fact[i-1]*i%mod;
    }
}

ll C(int t,int h) { return fact[h]*ifact[t]%mod*ifact[h-t]%mod; }

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> (a + 1);
        int c = 0, d = 0, cnt = 0;
        for (int i = 1; i <= n; ++i)
            if (a[i] == '0')
            {
                d++;
                c += cnt / 2;
                cnt = 0;
            }
            else cnt++;
        d++;
        c += cnt / 2;
        build(c + d);
        cout << C(d - 1, c + d - 1) << "\n";
    }
    return 0;
}