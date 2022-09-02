#include<bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b)
{
    while (a&&b)
    {
        if (a<b) swap(a, b);
        a = a%b;
    }
    return a+b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    long long p, q, b;
    for (int i = 0; i<n; i++)
    {
        cin>>p>>q>>b;
        long long t = gcd(b, q);
        do
        {
            t = gcd(t, q); q/=t; 
        }while (t!=1);
        if (p%q==0) cout<<"Finite"<<endl;
        else cout<<"Infinite"<<endl;
    }
}