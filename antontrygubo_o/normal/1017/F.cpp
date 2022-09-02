#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll N = 1;
ll A, B, C, D;
ll result = 0;
ll f(ll x)
{
    ll res = D%N;
    res = (res + (C*x)%N);
    res = (res + (((B*x)%N)*x)%N);
    res = (res + ((((((A*x)%N)*x)%N)*x)%N));
    res%=N;
    return res;
}
ll n;
const ll M1 = 20000;
const ll M = 300000000;
vector<int> primes;
vector<bool> small(20005, 0);

vector<int> big(20005, 0);

void del()
{
    for (int i = 0; i<big.size(); i++) big[i] = 0;
}

void solve(ll n, ll prime)
{
    ll res = 0;
        ll kek = f(prime);
        ll degprime = prime;
        while (degprime<=n)
        {
            res+=(kek*(n/degprime)%N);
            degprime*=prime;
            res%=N;
        }

    result = (result+res)%N;
}

void init()
{
    for (int i = 2; i<=M1; i++)
    {
        if (!small[i]) {primes.push_back(i); solve(n, i); for (int j = 2*i; j<=M1; j+=i) small[j] = 1;}
    }
    for (int i = M1; i<=M; i+=M1)
    {
        del();
        for (int j = 0; (j<primes.size()&&primes[j]<=M1); j++)
        {
            for (int k = ((i+primes[j]-1)/primes[j])*primes[j]; k<i+M1; k+=primes[j]) big[k%M1] = 1;
        }
        for (int j = i; j<i+M1; j++) if (big[j%M1]==0)  solve(n, j);
    }
}



int main()
{
    cin>>n;
    for (int i = 0; i<32; i++) N*=2;
    cin>>A>>B>>C>>D;
    init();
    cout<<result;
}