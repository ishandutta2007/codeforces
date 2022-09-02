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

vector<ll> fac(300050);

vector<ll> invfac(300050);

vector<int> primes(300050);
vector<bool> visited(300050);
vector<int> mu(300050);


void init()
{
    fac[0] = 1;
    for (int i = 1; i<300050; i++) fac[i] = (fac[i-1]*i)%p;
    for (int i = 0; i<300050; i++) invfac[i] = inv(fac[i]);
    
    mu[1] = 1;
    
    for (ll i = 2; i<300050; i++)
    {
        if (!visited[i]) {primes[i] = i; for (ll j = i*i; j<300050; j+=i) {visited[j] = true; primes[j] = i;}}
    }
    
    for (int i = 2; i<300050; i++)
    {
        int temp = primes[i];
        if ((i/temp)%temp == 0) mu[i] = 0;
        else mu[i] = -mu[i/temp];
    }
    
}

ll C(int n, int k)
{
    if (n<k) return 0;
    ll res = fac[n];
    res = (res*invfac[k])%p;
    res = (res*invfac[n-k])%p;
    return res;
}

vector<int> counter(300001);

void add(int n)
{
    for (int i = 1; i<sqrt(n); i++) if (n%i==0)
    {
        counter[i]++;
        counter[n/i]++;
    }
    int i = sqrt(n);
    if (i*i==n) counter[i]++;
}


bool check(int k)
{
    vector<int> c = counter;
    for (int i = 1; i<=300000; i++) c[i] = C(c[i], k);
    ll S = 0;
    for (int i = 1; i<=300000; i++) S = (S+c[i]*mu[i])%p;
    return (S!=0);
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    init();
    int n;
    cin>>n;
    vector<int> a(n);
    for (int i = 0; i<n; i++) cin>>a[i];
    for (int i = 0; i<n; i++) add(a[i]);
    int gcd = a[0];
    for (int i = 1; i<n; i++) gcd = __gcd(gcd, a[i]);
    if (gcd!=1) {cout<<-1; return 0;}
    int kek = 1;
    while (!check(kek)) kek++;
    cout<<kek;
}