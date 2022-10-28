#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e7+5;

int pi[N], rub[N], sieve[N];

inline int check(int k)
{
    int cur=k;
    int rev=0;
    while(k>0)
    {
        rev*=10;
        rev+=(k%10);
        k/=10;
    }
    return (rev==cur);
}

int32_t main()
{
    IOS;
    for(int i=2;i<N;i++)
        sieve[i]=1;
    for(int i=1;i<N;i++)
    {
        pi[i]=pi[i-1];
        if(sieve[i])
        {
            for(int j=2;i*j<N;j++)
                sieve[i*j]=0;
            pi[i]++;
        }
        rub[i]=rub[i-1];
        rub[i]+=check(i);
    }
    int p, q;
    cin>>p>>q;
    for(int i=N-1;i>=1;i--)
    {
        if(q*pi[i]<=p*rub[i])
        {
            cout<<i;
            return 0;
        }
    }
    cout<<"Palindromic tree is better than splay tree";
    return 0;
}