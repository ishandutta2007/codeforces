#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void print(vector<ll> &a)
{
    for (int i = 0; i<a.size(); i++) cout<<a[i]<<' ';
    cout<<endl;
}



const ll p = 1e9 + 7;
int squarefree(int n)
{
    for (int i = 2; i<=sqrt(n); i++) if (n%i==0)
    {
        while (n%(i*i)==0) n/=(i*i);
    }
    return n;
}

ll po(ll a, ll d)
{
    if (d==0) return 1;
    if (d%2==1) return (po(a, d-1)*a)%p;
    ll temp = po(a, d/2);
    return (temp*temp)%p;
}

ll inv(ll n)
{
    return po(n, p-2);
}

vector<ll> fac(400);

vector<ll> invfac(400);

void init()
{
    fac[0] = 1;
    for (int i = 1; i<400; i++) fac[i] = (fac[i-1]*i)%p;
    for (int i = 0; i<400; i++) invfac[i] = inv(fac[i]);
}

ll C(int n, int k)
{
    ll res = fac[n];
    res = (res*invfac[k])%p;
    res = (res*invfac[n-k])%p;
    return res;
}

vector<vector<ll>> dp;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    init();
    int n;
    cin>>n;
    vector<int> a(n);
    for (int i = 0; i<n; i++) cin>>a[i];
    for (int i = 0; i<n; i++) a[i] = squarefree(a[i]);
    sort(a.begin(), a.end());
    vector<int> b(n);
    b[0] = 0;
    for (int i = 1; i<n; i++)
    {
        if (a[i]==a[i-1]) b[i] = b[i-1];
        else b[i] = b[i-1] + 1;
    }
    
    for (int i = 0; i<n; i++) a[i] = b[i];
    
    
    int M = a[n-1];
    vector<int> count(M+1);
    for (int i = 0; i<n; i++) count[a[i]]++;
    
    for (int i = 0; i<=M; i++) dp.push_back(vector<ll>(n));
    
    vector<int> pref_sum(M+1);
    pref_sum[0] = count[0];
    for (int i = 1; i<=M; i++) pref_sum[i] = pref_sum[i-1] + count[i];
    
    
    dp[0][count[0]-1] = fac[count[0]];
    for (int i = 0; i<M; i++)
    {
        for (int j = 0; j<pref_sum[i]; j++) if (dp[i][j]!=0)
        {
            int s = j;
            int d = pref_sum[i] + 1 - s;
            for (int a = 0; a<=s; a++)
            for (int b = 0; b<=d; b++) if (a+b>0&&a+b<=count[i+1])
            {
                dp[i+1][s+count[i+1]-2*a-b]  = (dp[i+1][s+count[i+1]-2*a-b] + (dp[i][s]*((((C(s, a)*C(d, b))%p)*((C(count[i+1]-1, a+b-1)*fac[count[i+1]])%p))%p))%p )%p;
            }
        }
    }
    
    cout<<dp[M][0]<<endl;
    
}