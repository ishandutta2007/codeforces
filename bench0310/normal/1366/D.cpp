#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const int N=10000000;
    vector<int> sieve(N+1,0);
    for(int i=0;i<=N;i++) sieve[i]=i;
    for(ll i=2;i<=N;i++)
    {
        if(sieve[i]!=i) continue;
        for(ll j=i*i;j<=N;j+=i) if(sieve[j]==j) sieve[j]=i;
    }
    int n;
    cin >> n;
    vector<int> one(n,-1);
    vector<int> two(n,-1);
    for(int o=0;o<n;o++)
    {
        int a;
        cin >> a;
        int x=a;
        vector<int> v;
        while(x>1)
        {
            int p=sieve[x];
            int now=1;
            while(sieve[x]==p)
            {
                now*=p;
                x/=p;
            }
            v.push_back(now);
        }
        for(int p:v) if(p!=a&&gcd(a,p+a/p)==1) tie(one[o],two[o])=make_pair(p,a/p);
    }
    for(int i=0;i<n;i++) cout << one[i] << " \n"[i==n-1];
    for(int i=0;i<n;i++) cout << two[i] << " \n"[i==n-1];
    return 0;
}