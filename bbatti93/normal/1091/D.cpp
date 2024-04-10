#include <bits/stdc++.h>

using namespace std;

long long n, ki, fact[1000001], fi[1000001];

const long long M=998244353;

long long power(long long x, long long y)
{
    if (y == 0) return 1;
    long long p = power(x, y/2) % M;
    p = (p * p) % M;
    return (y%2 == 0)? p : (x * p) % M;
}
long long mi(int a)
{
    return power(a, M-2);
}




int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    fact[0]=1;
    fi[0]=1;
    for(int i=1;i<=n;i++) {
        fact[i]=(i*fact[i-1])%M;
        fi[i]=mi(fact[i]);
        //cout << i << " " << fact[i] << " " << fact[i]*fi[i]%M << endl;
    }
    for(int i=1;i<n;i++) ki=(ki+fi[i])%M;
    ki=(fact[n]*(n+M-ki))%M;
    cout << ki << endl;
    return 0;
}